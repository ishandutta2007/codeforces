#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif

#include<iostream>
#include<vector>
#include<climits>
#include<cassert>

struct ST{
	std::vector<int64_t> d,lazy;
	// d: min in range
	// lazy[x] affects d[x]
	ST(std::vector<int64_t> const& a):d(2*a.size()),lazy(2*a.size()){
		std::copy(begin(a),end(a),begin(d)+a.size());
		for(unsigned i=a.size()-1;i;--i)
			d[i]=std::min(d[i<<1],d[i<<1|1]);
	}

	int64_t getd(unsigned x)const{
		return lazy[x]+d[x];
	}

	int64_t getmin(unsigned l,unsigned r){
		l+=d.size()/2;
		r+=d.size()/2;
		pushall(l);
		pushall(r-1);

		int64_t ans=INT64_MAX;
		while(l<r){
			if(l&1)ans=std::min(ans,getd(l++));
			if(r&1)ans=std::min(ans,getd(--r));
			l>>=1;r>>=1;
		}
		return ans;
	}

	void add(unsigned l,unsigned r,int64_t del){
		if(l==r)return;
		l+=d.size()/2;
		r+=d.size()/2;
		unsigned l0=l,r0=r;
		pushall(l0);pushall(r0-1);
		while(l<r){
			if(l&1)lazy[l++]+=del;
			if(r&1)lazy[--r]+=del;
			l>>=1;r>>=1;
		}
		update(l0);update(r0-1);
	}

	void pushall(unsigned i){
		for(int nshr=31^__builtin_clz(i);nshr!=0;--nshr){
			unsigned n=i>>nshr;
			int64_t& l=lazy[n];
			if(l){
				d[n]+=l;
				lazy[n<<1]+=l;
				lazy[n<<1|1]+=l;
				l=0;
			}
		}
	}
	
	void update(unsigned i){
		for(i>>=1;i!=0;i>>=1){
			d[i]=std::min(getd(i<<1),getd(i<<1|1));
		}
	}

};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	
	int n;std::cin>>n;
	std::vector<int64_t> a(n);for(auto& x:a)std::cin>>x;
	ST s(a);

	std::vector<int> ans(n);
	int last=0;

	while(last<n){

		assert(std::cerr<<" == ");
		for(int i=0;i<n;++i)
			assert(std::cerr<<s.getmin(i,i+1)<<' ');
		assert(std::cerr<<'\n');

		int l=0;
		// find max l such that min[l..n] == 0 ( O(log ^2 n) )
		for(int step=1<<25;step;step>>=1){
			if(l+step<a.size()&&s.getmin(l+step,a.size())==0){
				l+=step;
			}
		}

		ans[l]=++last;
		s.add(l,l+1,1000000000000000LL);
		s.add(l+1,a.size(),-last);
	}
	for(auto x:ans)std::cout<<x<<' ';
	std::cout<<'\n';
}