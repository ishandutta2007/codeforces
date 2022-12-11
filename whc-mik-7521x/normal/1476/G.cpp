#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,s,a[N],bel[N],ans[N],cnt[N],ccnt[N];
int op,L,R,K,T,x,cntr,cntp,l=1,r,t,be,st=100001;
int last[N],nxt[N],pos[N],top;
struct node{
	int l,r,k,t,id;
	bool operator<(const node x)const{ 
		return bel[l]==bel[x.l]?(bel[r]==bel[x.r]?t<x.t:r<x.r):l<x.l;
	}
}p[N];
struct dat{ 
	int i,from,to;
}q[N];
void ins(int x){
	if(x==0) return;
	if(!ccnt[x]++) nxt[last[st]]=x,last[x]=last[st],nxt[x]=st,last[st]=x;
}
void del(int x){
	if(x==0) return;
	if(!--ccnt[x]) {
		if(x==be)be=nxt[x];
		if(x==st)st=last[x];
		last[nxt[x]]=last[x],nxt[last[x]]=nxt[x];
	}
}
void add(int x){
	del(cnt[x]),ins(++cnt[x]);
}
void dele(int x){
	del(cnt[x]),ins(--cnt[x]);
}
int solve(int x){
	top=0;
	for(int i=be;i!=st;i=nxt[i]) if(i!=0) pos[++top]=i;
	sort(pos+1,pos+top+1);
	int sum=0,mi=2147483647,ll=1,rr=1;
	while(rr<=top){
		sum+=ccnt[pos[rr++]];
		if(sum<x) continue;
		while(sum>=x+ccnt[pos[ll]]) sum-=ccnt[pos[ll++]];
		mi=min(mi,pos[rr-1]-pos[ll]);
	}
	return mi==2147483647?-1:mi;
}
int main() {
	nxt[0]=nxt[100001]=100001;
	scanf("%d%d",&n,&m);
	s=pow(n,2.0/3);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		bel[i]=(i+s-1)/s;
	}
	for(int i=1;i<=m;++i){
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d%d",&L,&R,&K);
			p[++cntp].l=L;
			p[cntp].r=R;
			p[cntp].k=K;
			p[cntp].t=cntr;
			p[cntp].id=cntp;
		}
		else{
			scanf("%d%d",&x,&K);
			q[++cntr].i=x;
			q[cntr].from=a[x];
			q[cntr].to=a[x]=K;
		}
	}
	for(int i=cntr;i>0;--i)a[q[i].i]=q[i].from;
	sort(p+1,p+cntp+1);
	for(int i=1;i<=cntp;++i){
		L=p[i].l,R=p[i].r,K=p[i].k,T=p[i].t;
		while(t<T){
			++t;
			if(q[t].i>=l&&q[t].i<=r)add(q[t].to),dele(q[t].from);
			a[q[t].i]=q[t].to;
		} 
		while(t>T) {
			if(q[t].i>=l&&q[t].i<=r)dele(q[t].to),add(q[t].from);
			a[q[t].i]=q[t].from;
			--t;
		}
		while(l>L)add(a[--l]);
		while(r<R)add(a[++r]);
		while(l<L)dele(a[l++]);
		while(r>R)dele(a[r--]);
		ans[p[i].id]=solve(K);
	}
	for(int i=1;i<=cntp;++i){
		printf("%d\n",ans[i]);
	}
	return 0;
}