#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=1e6+10;
int n,m,ti,tp,a[N],d[N],p[N],pos[N],pd[N];
long long ans[M];
vector<pair<int,int>>qu[M];
vector<int>w[N];
struct seg{
	struct node{
		long long val,cl,tag,len;
	}t[N<<2];
	void build(int rt,int l,int r){
		t[rt].len=r-l+1;
		if(l==r)return;
		int mid=(l+r)>>1;
		build(rt<<1,l,mid);
		build(rt<<1|1,mid+1,r);
	}
	void pushdown(int rt){
		if(t[rt].val==t[rt].len){
			t[rt<<1].val=t[rt<<1].len;
			t[rt<<1|1].val=t[rt<<1|1].len;
		}
		if(t[rt].val==0){
			t[rt<<1].val=0;
			t[rt<<1|1].val=0;
		}
		t[rt<<1].tag+=t[rt].tag;
		t[rt<<1].cl+=t[rt].tag*t[rt<<1].len;
		t[rt<<1|1].tag+=t[rt].tag;
		t[rt<<1|1].cl+=t[rt].tag*t[rt<<1|1].len;
		t[rt].tag=0;
	}
	void pushup(int rt){
		t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
		t[rt].cl=t[rt<<1].cl+t[rt<<1|1].cl;
	}
	void modify(int rt,int l,int r,int L,int R){
		if(L<=l&&r<=R){
			t[rt].tag+=ti;
			t[rt].cl+=ti*t[rt].len;
			t[rt].val=0;
			return;
		}
		pushdown(rt);
		int mid=(l+r)>>1;
		if(L<=mid)modify(rt<<1,l,mid,L,R);
		if(R>mid)modify(rt<<1|1,mid+1,r,L,R);
		pushup(rt);
	}
	void upd(int rt,int l,int r,int L,int R){
		if(L<=l&&r<=R){
			t[rt].tag-=ti;
			t[rt].val=t[rt].len;
			t[rt].cl-=ti*t[rt].len;
			return;
		}
		pushdown(rt);
		int mid=(l+r)>>1;
		if(L<=mid)upd(rt<<1,l,mid,L,R);
		if(R>mid)upd(rt<<1|1,mid+1,r,L,R);
		pushup(rt);
	}
	long long query(int rt,int l,int r,int L,int R){
		if(L<=l&&r<=R)return t[rt].cl+ti*t[rt].val;
		pushdown(rt);
		int mid=(l+r)>>1;
		long long ans=0;
		if(L<=mid)ans+=query(rt<<1,l,mid,L,R);
		if(R>mid)ans+=query(rt<<1|1,mid+1,r,L,R);
		return ans;
	}
}tr;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),pos[a[i]]=i;
	for(int i=1;i<=m;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		qu[r].push_back({l,i});
	}
	for(int i=1;i<=n;i++){
		for(int o=i;o<=n;o+=i){
			w[o].push_back(i);
		}
	}
	tr.build(1,1,n);
	for(int i=1;i<=n;i++){
		while(tp&&a[d[tp]]<a[i]){
			if(p[tp]>d[tp-1])tr.modify(1,1,n,d[tp-1]+1,p[tp]);
			pd[d[tp]]=0;
			tp--;
		}
		for(int o=a[i];o<=n;o+=a[i]){
			if(pd[pos[o]]){
				int pt=pd[pos[o]],l=d[pt-1]+1,r=d[pt],nx=pos[o/a[i]];
				if(nx<l||nx>=i)continue;
				nx=min(nx,r);
				if(nx<=p[pt])continue;
				tr.upd(1,1,n,p[pt]+1,nx);
				p[pt]=nx;
			}
		}
		d[++tp]=i;
		pd[i]=tp;
		p[tp]=d[tp-1];
		for(auto o:w[a[i]]){
			int l=d[tp-1]+1;
			int pos1=pos[o],pos2=pos[a[i]/o];
			if(pos2<=pos1)continue;
			if(pos1<l||pos2>i)continue;
			if(pos1<=p[tp])continue;
			tr.upd(1,1,n,p[tp]+1,pos1);
			p[tp]=pos1;
		}
		ti++;
		for(auto t:qu[i])ans[t.second]=tr.query(1,1,n,t.first,i);
	}
	for(int i=1;i<=m;i++)printf("%lld\n",ans[i]);	
	return 0;
}