// forgot to read the condition that r0!=r1. Fortunately int this case
// it isn't a large problem.
// :( even with such an easy problem like this?...
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>


template int const& std::min<int>(int const&,int const&);

template<class T=int,auto f=(T const&(*)(T const&,T const&))std::min<T>>
struct RMQ{
	std::vector<std::vector<T>> d;
	RMQ():d(){}
	RMQ(std::vector<T> x):d(){
		assign(std::move(x));
	}
	void assign(std::vector<T> x){
		d.assign(1,std::move(x));
		for(int step=1;step<(int)d.back().size();step<<=1){
			std::vector<T> const& a=d.back();
			std::vector<T> b(begin(a),end(a)-step);
			std::transform(begin(b),end(b),begin(a)+step,begin(b),f);
			d.push_back(std::move(b));
		}
	}
	T operator[](int i)const{ return d[0][i]; }
	T get(int l,int r)const{
		assert(l<r);
		int layer=std::__lg(r-l);
		return f(d[layer][l],d[layer][r-(1<<layer)]);
	}
	template<class U> T get(U lr)const{
		auto [l,r]=lr;
		return get(l,r);
	}
	T getrange(int l,int r)const{
		return get(std::minmax(l,r));
	}

};

struct suffixarray_t{
	std::vector<int> rankof;
	std::vector<int> order;// list of start indices sorted by order
};
suffixarray_t suffixarray(std::string const& s){
	suffixarray_t out{std::vector<int>(s.size()+1),std::vector<int>(s.size()+1)};
	auto& [rankof,order]=out;

	std::copy(begin(s),end(s),begin(rankof));

	std::vector<int> cnt; // temporary array for counting sort
	std::vector<std::vector<int>::iterator> it;

	std::vector<int> newrank,oldorder;

	unsigned prefix_len=1,nrank=128;
	while(true){
		// sort order by second half
		cnt.assign(nrank,0);
		for(unsigned x=0;x<order.size();++x)
			++cnt[x+prefix_len>=rankof.size() ? 0 : rankof[x+prefix_len]]; // TODO inefficient branch/cmov

		it.resize(nrank);
		it[0]=begin(order);
		for(unsigned i=1;i<nrank;++i)
			it[i]=it[i-1]+cnt[i-1];

		for(unsigned x=0;x<rankof.size();++x)
			*it[x+prefix_len>=rankof.size() ? 0 : rankof[x+prefix_len]]++=x;

		// stable sort order by first half
		cnt.assign(nrank,0);
		for(int x:rankof)++cnt[x];

		std::swap(order,oldorder);
		order.resize(oldorder.size());

		it.resize(nrank);
		it[0]=begin(order);
		for(unsigned i=1;i<nrank;++i)
			it[i]=it[i-1]+cnt[i-1];

		for(auto x:oldorder)
			*it[rankof[x]]++=x;

		// recalculate rank
		newrank.resize(rankof.size());
		nrank=1;
		newrank[order[0]]=0;
		for(unsigned i=1;i<order.size();++i){
			auto a=order[i-1],b=order[i];
			if(rankof[a]!=rankof[b] or rankof[a+prefix_len]!=rankof[b+prefix_len])
				++nrank;
			newrank[b]=nrank-1;
		}

		prefix_len*=2;
		std::swap(rankof,newrank);
		if(nrank==rankof.size())
			break;
	}

	return out;
}

std::vector<int> lcp(std::string const& s,std::vector<int> const& rankof,std::vector<int> const& order){
	assert(rankof.size()==s.size()+1);
	assert(rankof.size()==order.size());
	std::vector<int> out(s.size());
	int minlcp=0;
	for(unsigned i=0;i<s.size();++i){
		unsigned r=rankof[i];
		assert(order[r]==(int)i);
		if(r+1==order.size()){
			assert(minlcp==0);
			continue;
		}
		unsigned j=order[r+1];

		while(s[i+minlcp]==s[j+minlcp]) ++minlcp;

		out[r]=minlcp;
		if(minlcp) --minlcp;
	}
	return out;
}



int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::string one, two; std::cin>>one>>two;
	for(auto & c: one) c=char(c-'0');
	if(one[0]) for(auto & c: one) c=not c;

	auto const [rankof, order]=suffixarray(two);
	auto const lcp_=lcp(two, rankof, order);
	RMQ const rmq(lcp_);

	auto num1=std::accumulate(begin(one),end(one), 0);
	auto num0=(int)one.size()-num1;

	auto result=0;
	for(int len0=1;len0<(int)two.size();++len0) {
		auto remainingLen=two.size()-(int64_t)num0*len0;
		if(remainingLen<=0 or remainingLen%num1!=0) continue;
		auto len1=int(remainingLen/num1);

		auto first0=0, first1=-1;
		assert(one[0]==0);

		auto cur=0;
		for(auto c: one){
			if(c){
				if(first1<0)
					first1=cur;
				else if(rmq.getrange(rankof[first1], rankof[cur])<len1)
					goto nextLen0;
				cur+=len1;
			}else{
				if(cur!=0 and rmq.getrange(rankof[first0], rankof[cur])<len0)
					goto nextLen0;
				cur+=len0;
			}
		}
		if(len0!=len1 or rmq.getrange(rankof[first0], rankof[first1])<len0)
			++result;
nextLen0:;
	}
	std::cout<<result<<'\n';
}