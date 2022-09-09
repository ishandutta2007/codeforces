#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=150050;
const int M=4*N;
const int inf=1e9;
int fwr,bwr,tsz,ls[M],rs[M],sec[M],fir[M],cnt[M],lzy[M],add[M],sz[M];
ll sum[M];
void Build(int &c,int ss,int se){
	c=++tsz;
	cnt[c]=0;
	sum[c]=0;
	fir[c]=sec[c]=-inf;
	lzy[c]=inf;
	add[c]=0;
	sz[c]=0;
	if(ss==se)return;
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
}
void upd(int c,int x,int y){
	sum[c]+=(ll)sz[c]*y;
	fir[c]+=y;
	sec[c]+=y;
	lzy[c]+=y;
	add[c]+=y;
	if(fir[c]>x && sec[c]<x){
		sum[c]-=(ll)cnt[c]*(fir[c]-x);
		fir[c]=x;
		lzy[c]=min(lzy[c],x);
	}
}
void push(int c){upd(ls[c],lzy[c],add[c]);upd(rs[c],lzy[c],add[c]);lzy[c]=inf;add[c]=0;}
void pull(int c){
	if(fir[ls[c]]==fir[rs[c]]){
		cnt[c]=cnt[ls[c]]+cnt[rs[c]];
		fir[c]=fir[ls[c]];
		sec[c]=max(sec[ls[c]],sec[rs[c]]);
	}else if(fir[ls[c]]>fir[rs[c]]){
		cnt[c]=cnt[ls[c]];
		fir[c]=fir[ls[c]];
		sec[c]=max(sec[ls[c]],fir[rs[c]]);
	}else{
		cnt[c]=cnt[rs[c]];
		fir[c]=fir[rs[c]];
		sec[c]=max(fir[ls[c]],sec[rs[c]]);
	}
	sum[c]=sum[ls[c]]+sum[rs[c]];
	sz[c]=sz[ls[c]]+sz[rs[c]];
}
void Rng(int c,int ss,int se,int qs,int qe,int x){
	if(qs>qe || qs>se || ss>qe || fir[c]<=x)return;
	if(qs<=ss && qe>=se && sec[c]<x){upd(c,x,0);return;}
	int mid=ss+se>>1;
	push(c);
	Rng(ls[c],ss,mid,qs,qe,x);
	Rng(rs[c],mid+1,se,qs,qe,x);
	pull(c);
}
void Add(int c,int ss,int se,int qs,int qe,int x){
	if(qs>qe || qs>se || ss>qe)return;
	if(qs<=ss && qe>=se){upd(c,inf,x);return;}
	int mid=ss+se>>1;
	push(c);
	Add(ls[c],ss,mid,qs,qe,x);
	Add(rs[c],mid+1,se,qs,qe,x);
	pull(c);
}
void Set(int c,int ss,int se,int qi,int x){
	if(ss==se){
		sum[c]=x;
		fir[c]=x;
		sec[c]=-inf;
		cnt[c]=1;
		sz[c]=1;
		return;
	}
	int mid=ss+se>>1;
	push(c);
	if(qi<=mid)Set(ls[c],ss,mid,qi,x);
	else Set(rs[c],mid+1,se,qi,x);
	pull(c);
}
ll Get(int c,int ss,int se,int qs,int qe){
	if(qs>qe || qs>se || ss>qe)return 0;
	if(qs<=ss && qe>=se)return sum[c];
	int mid=ss+se>>1;
	push(c);
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
struct BIT{
	int sum[N];
	BIT(){}
	void Set(int i,int f){for(;i<N;i+=i&-i)sum[i]+=f;}
	int Get(int i){int ans=0;for(;i;i-=i&-i)ans+=sum[i];return ans;}
}BT;
int a[N],pos[N];
int main(){
	int n;
	scanf("%i",&n);
	for(int i=1;i<=n;i++)scanf("%i",&a[i]),pos[a[i]]=i;
	Build(fwr,1,n);
	Build(bwr,1,n);
	for(int i=1;i<=n;i++){
		BT.Set(pos[i],1);
		int rel=BT.Get(pos[i]);
		Set(fwr,1,n,pos[i],i);
		Set(bwr,1,n,pos[i],0);
		Add(fwr,1,n,pos[i]+1,n,1);
		Rng(fwr,1,n,1,pos[i]-1,rel-1);
		Add(bwr,1,n,pos[i]+1,n,-1);
		Rng(bwr,1,n,pos[i]+1,n,-rel);
		ll ans=sum[fwr]+sum[bwr];
		printf("%lld\n",ans);
	}
	return 0;
}