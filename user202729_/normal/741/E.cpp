// Easy problem with tedious implementation...
// UPD: Typed `++step` instead of `step<<=1` in RMQ initialization.
// How can this bug be undiscovered for so long...
// When I generate tests with s.size()<=5, the bug is not discovered at all. Isn't 5 large enough?
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<vector>
#include<string>
#include<algorithm>

template int const& std::min<int>(int const&,int const&); // Have to explicitly instantiate the template. Why?

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

#include<climits>
#include<array>
#include<numeric>
#include<iostream>

int ceildiv(int x,int y){
	assert(x>-y and y>0);
	return (x+y-1)/y;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::string s,t;int nquery;
	std::cin>>s>>t>>nquery;

	auto st=s+'$'+t;
	auto [rankof,order]=suffixarray(st);
	auto lcp_=lcp(st,rankof,order);
	RMQ rmqlcp(lcp_);

	auto const cmp=[](auto const& x,auto const& y){ // -> x <=> y
		return (x>y)-(x<y);
	};

	auto const cmp_0=[&](int x,int y,int len){ // -> st[x:x+len] <=> st[y:y+len]
		assert(x!=y);
		if(rmqlcp.getrange(rankof[x],rankof[y])<len)
			return cmp(rankof[x],rankof[y]);
		else
			return 0;
	};
	auto const cmp_1=[&](int x,int l1,int y,int l2){ // -> st[x:x+l1] + st[y:y+l2] <=> st[y:y+l2] + st[x:x+l1]
		assert(l1>=l2);
		assert(l2>=0);
		int out=0;
		if(out==0) out=cmp_0(x,y,l2);
		if(out==0) out=cmp_0(x+l2,x,l1-l2);
		if(out==0) out=cmp_0(y,x+l1-l2,l2);
		assert(out==cmp(
					st.substr(x,l1)+st.substr(y,l2),
					st.substr(y,l2)+st.substr(x,l1)));
		return out;
	};
	auto const cmp_2=[&](int x,int l1,int y,int l2){ // -> st[x:x+l1] + st[y:y+l2] <=> st[y:y+l2] + st[x:x+l1]
		if(l1>=l2)
			return cmp_1(x,l1,y,l2);
		else
			return -cmp_1(y,l2,x,l1);
	};
	auto const more_interesting_1=[&](int x,int y){ // -> (t + s[x:y]) < (s[x:y] + t)
		assert(x<=(int)s.size());
		assert(y<=(int)s.size());
		assert(x<=y);
		return cmp_2((int)s.size()+1,(int)t.size(),x,y-x);
	};

	auto const more_interesting_2=[&](int x,int y){ // same as above but support x>y
		if(x==y)return false;
		if(x<y)return more_interesting_1(x,y)<0;
		else return more_interesting_1(y,x)>0;
	};

	auto const more_interesting=[&](int x,int y){ // same as above but with assertion
		auto out=more_interesting_2(x,y);
		assert(out==((s.substr(0,x)+t+s.substr(x)) < (s.substr(0,y)+t+s.substr(y)))); // expensive assertion
		return out;
	};

	std::vector<int> options(s.size()+1);
	std::iota(begin(options),end(options),0);
	std::sort(begin(options),end(options),more_interesting);
	
	std::vector<int> optionrank(s.size()+1);
	int lastrank=optionrank[options[0]]=0;
	for(unsigned i=1;i<optionrank.size();++i){
		assert(not more_interesting(options[i],options[i-1]));
		if(more_interesting(options[i-1],options[i]))
			++lastrank;
		optionrank[options[i]]=lastrank;
	}

	RMQ<std::pair<int,int>> prep; // [k-1][value mod k] = RMQ of {optionrank,index}
	{
		std::vector<std::pair<int,int>> x(optionrank.size());
		for(int i=0;i<(int)optionrank.size();++i)
			x[i]={optionrank[i],i};
		prep.assign(std::move(x));
	}

	int const ENDSMALLK=300;

	/*
	std::array<std::vector<RMQ<std::pair<int,int>>>,ENDSMALLK-1> prep; // [k-1][value mod k] = RMQ of {optionrank,index}
	for(int k=1;k<ENDSMALLK;++k){
	}
	*/

	std::vector<int> out(nquery);

	struct query{
		int l,r,x,y;
		int ind;
	};
	std::vector<std::vector<query>> queries_for_k(ENDSMALLK);
	for(int ind=0;ind<nquery;++ind){
		query q;
		auto& [l,r,x,y,ind_]=q;
		int k;
		std::cin>>l>>r>>k>>x>>y;
		ind_=ind;
		++r;++y;
		assert(0<=l and l<r and r<=(int)s.size()+1);
		assert(0<=x and x<y and y<=k);

		if(l/k==r/k or (x==0 and y==k)){ // special case. Only improves performance int this specific case. Can be removed without affecting solution correctness.
			if(l%k<x) l=l/k*k+x;
			if(l%k>y) l=l/k*k+y;
			if(r%k<x) r=r/k*k+x;
			if(r%k>y) r=r/k*k+y;
			if(l<r)
				out[ind]=prep.get(l,r).second;
			else
				out[ind]=-1;
		}else if(k>=ENDSMALLK){
			std::pair<int,int> out1{INT_MAX,-1};
			if(x<=l%k and l%k<y){
				int l1=l/k*k;
				out1=std::min(out1,prep.get(l,l1+y));
				l=l1+k+x;
			}else{
				l=ceildiv(l-x,k)*k+x;
			}
			assert(l%k==x);
			while(true){
				auto r1=l+y-x;
				if(r<=r1){
					if(l>=r)
						break;
					out1=std::min(out1,prep.get(l,r));
					break;
				}
				out1=std::min(out1,prep.get(l,r1));
				l+=k;
			}
			out[ind]=out1.second;
		}else{
			queries_for_k[k].push_back(q);
		}
	}

	for(int k=1;k<(int)queries_for_k.size();++k){
		std::vector<RMQ<std::pair<int,int>>> prep2(k);
		for(int mod=0;mod<k;++mod){
			std::vector<std::pair<int,int>> x;
			x.reserve(optionrank.size()/k+1);
			for(int i=mod;i<(int)optionrank.size();i+=k)
				x.push_back({optionrank[i],i});
			prep2[mod].assign(std::move(x));
		} // total complexity: s.size() * log(s.size()/k)

		for(auto const [l,r,x,y,ind]:queries_for_k[k]){
			std::pair<int,int> out1{INT_MAX,-1};
			for(int mod_k=x;mod_k<y;++mod_k){
				int l1=ceildiv(l-mod_k,k);
				int r1=ceildiv(r-mod_k,k);
				if(l1<r1) out1=std::min(out1,prep2[mod_k].get(l1,r1));
			}
			out[ind]=out1.second;
		} // total complexity: k * nquery
	}

	for(auto x:out)std::cout<<x<<' ';
	std::cout<<'\n';
}