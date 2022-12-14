// Forget to add mod... what a mistake.
// UPD2: I knew what the bug is int 10 seconstd:: of thinking. Why can't I do that before submitting?...
// It took surprisingly long to fix the bug. Half of the problem is because of wrong test generator
// and wrong assertions. (How annoying.)
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<vector>
#include<iostream>

int const MOD=1000000007;

struct ST{
	struct force_check{};

	struct node{
		int lpos,rpos;
		int64_t sumw;
		int lw,rw;

		constexpr node(): lpos(),rpos(),sumw(), lw(),rw(){}
		constexpr node(int pos,int w):
			lpos(pos),rpos(pos),sumw(w),
			lw(0),rw(0){}

		constexpr node(node l,node r,force_check):
			lpos(l.lpos),
			rpos(r.rpos),
			sumw(l.sumw+r.sumw),
			lw(int((l.lw + r.lw + (int64_t)r.sumw%MOD*(r.lpos -l.lpos))%MOD)),
			rw(int((r.rw + l.rw + (int64_t)l.sumw%MOD*(r.rpos -l.rpos))%MOD))
		{
			assert(l.rpos<=r.lpos);
			assert(lw>=0);
			assert(rw>=0);
		}
		constexpr node(node l,node r):
			lpos(l.lpos),
			rpos(r.rpos),
			sumw(l.sumw+r.sumw),
			lw(int((l.lw + r.lw + (int64_t)r.sumw%MOD*(r.lpos -l.lpos))%MOD)),
			rw(int((r.rw + l.rw + (int64_t)l.sumw%MOD*(r.rpos -l.rpos))%MOD))
		{}
	};
	std::vector<node> d;

	void build(){
		assert(not d.empty() and d.size()%2==0);
		for(auto i=d.size()/2;--i;)
			d[i]=node(d[i<<1],d[i<<1|1]);
	}

	void update_weight(int pos,int w){
		pos+=int(d.size()/2);
		assert(d[pos].lpos==d[pos].rpos);
		d[pos]=node(d[pos].lpos,w);
		for(pos>>=1;pos;pos>>=1)
			d[pos]=node(d[pos<<1],d[pos<<1|1]);
	}

	node get(int nodel,int noder)const{
		assert(nodel>=int(d.size()/2));
		if(nodel==noder){
			return {}; // lpos/rpos values are **NOT** correct
		}
		assert(noder>nodel);

		if(noder-nodel==1) return d[nodel];

		node ansl=d[nodel++];
		node ansr=d[--noder];

		while(nodel<noder){
			if(nodel&1)ansl=node(ansl,d[nodel++], force_check());
			if(noder&1)ansr=node(d[--noder],ansr, force_check());
			nodel>>=1;
			noder>>=1;
		}
		return node(ansl,ansr);
	}

	int answer_query(int l,int r)const{
		l+=int(d.size()/2);
		r+=int(d.size()/2);

		int64_t sumw=get(l,r).sumw;
		int mid=l;
		// find max mid such that get(l,mid).sumw <= sumw/2
		int64_t rem=sumw/2;
		while(d[mid].sumw<=rem){
			if(mid&1){ rem-=d[mid].sumw; ++mid; }
			mid>>=1;
		}
		while(mid<int(d.size()/2)){
			mid<<=1;
			if(d[mid].sumw<=rem){ rem-=d[mid].sumw; ++mid; }
		}
		assert(d[mid].sumw>rem);
		assert(rem+get(l,mid).sumw==sumw/2);
		assert(rem>=0);
		assert(l<=mid and mid<r);

		return (get(l,mid+1).rw+get(mid,r).lw)%MOD;
	}
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,nquery;std::cin>>n>>nquery;

	ST st;
	st.d.resize(n*2);

	{
		std::vector<int> a(n);
		for(int& ai:a)std::cin>>ai;

		for(int i=1;i<n;++i)
			assert(a[i-1]<a[i]);

		for(int i=0;i<n;++i){
			int wi;std::cin>>wi;
			st.d[i+n]=ST::node(a[i]-i,wi);
		}

		st.build();
	}

	while(nquery--){
		int x,y;std::cin>>x>>y;
		if(x<0)
			st.update_weight(-x-1,y);
		else
			std::cout<<st.answer_query(x-1,y)%MOD<<'\n';
	}
}