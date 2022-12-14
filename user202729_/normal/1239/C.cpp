#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif

#include<iostream>
#include<cassert>
#include<queue>
#include<climits>
#include<algorithm>
#include<vector>
#include<set>


struct ST{
	std::vector<std::pair<int64_t,int64_t>> d;

	ST(int64_t n):d(2*n,{INT64_MAX,INT64_MAX}){}

	void set(int64_t i,std::pair<int64_t,int64_t> x){
		i+=int64_t(d.size()/2);
		d[i]=x;
		for(i>>=1;i;i>>=1)
			d[i]=std::min(d[i<<1],d[i<<1|1]);
	}

	std::pair<int64_t,int64_t> min(int64_t l,int64_t r)const{
		l+=int64_t(d.size()/2);
		r+=int64_t(d.size()/2);
		std::pair<int64_t,int64_t> ans{INT64_MAX,INT64_MAX};
		while(l<r){
			if(l&1)ans=std::min(ans,d[l++]);
			if(r&1)ans=std::min(ans,d[--r]);
			l>>=1;r>>=1;
		}
		return ans;
	}

	int64_t getfirst_le(int64_t first)const{
		auto x=int64_t(d.size()/2);
		while(d[x].first>first)
			if(x&1)
				++x;
			else
				x>>=1;
		while(x<int64_t(d.size()/2)){
			x<<=1;
			if(d[x].first>first)
				++x;
		}
		assert(d[x].first<=first);
		return x-int64_t(d.size()/2);
	}
};

struct ev{
	int64_t t,ind;
	bool operator<(ev e)const{
		return t!=e.t ? t>e.t : ind>e.ind;
	}
};
struct ev_by_ind{
	bool operator()(ev a,ev b)const{
		return a.ind<b.ind;
	}
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int64_t n,p;std::cin>>n>>p;

	ST st(n);

	for(int64_t i=0;i<n;++i){
		int64_t time;std::cin>>time;
		st.set(i,{time,i});
	}

	std::queue<int64_t> q;
	std::set<int64_t> setq;setq.insert(n);
	int64_t time=0;

	std::vector<int64_t> ans(n);

	while(true){
		auto [time1,ind]=st.min(0,*setq.begin());
		if(time1==INT64_MAX&&q.empty())
			break;
		if(!q.empty()&& ( time+p<=time1 )){
			int64_t ind2=q.front();
			q.pop();
			setq.erase(setq.find(ind2));
			// ind2 will return to their seat before ind get the noodle
			time+=p;
			assert(std::cerr<<ind2<<" get nd at "<<time<<"\n");
			ans[ind2]=time;
		}else{
			// the first person with time' <= time+p will enter the queue (possibly ind)
			assert(ind<INT64_MAX);
			if(time1 <=time){
				ind=st.getfirst_le((int64_t)std::min<int64_t>(time,INT64_MAX-1));
				assert(ind<INT64_MAX);
			}else if(q.empty())
				time=time1;
			assert(std::cerr<<ind<<" enter q\n");
			q.push(ind);
			setq.insert(ind);
			st.set(ind,{INT64_MAX,INT64_MAX});
		}
	}

	for(auto x:ans)std::cout<<x<<' ';
	std::cout<<'\n';
}