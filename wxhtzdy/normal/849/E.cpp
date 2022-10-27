#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100005;
const int M=N*30;
int n,q,a[N],root[M],st[M],tsz,ls[M],rs[M];
set<int> pos[N];
vector<int> vals[M];
vector<ll> fenw[M];
void Add(int v,int qi,int qv){
	qi=lower_bound(vals[v].begin(),vals[v].end(),qi)-vals[v].begin();
	for(;qi<fenw[v].size();qi|=(qi+1))fenw[v][qi]+=qv;
}
void Update(int&v,int l,int r,int qi,int fi,int qv){
	if(!v)v=++tsz;
//	printf("2D v=%d l=%d r=%d qi=%d fi=%d qv=%d\n",v,l,r,qi,fi,qv);
	Add(v,fi,qv);
	if(l==r)return;
	int mid=l+r>>1;
	if(qi<=mid)Update(ls[v],l,mid,qi,fi,qv);
	else Update(rs[v],mid+1,r,qi,fi,qv);
}
void Insert0(int&v,int l,int r,int qi,int fi,int qv){
	if(!v)v=++tsz;
	vals[v].push_back(fi);
	if(l==r)return;
	int mid=l+r>>1;
	if(qi<=mid)Insert0(ls[v],l,mid,qi,fi,qv);
	else Insert0(rs[v],mid+1,r,qi,fi,qv);
}
ll Get(int v,int r){
	auto it=lower_bound(vals[v].begin(),vals[v].end(),r+1);
	if(it==vals[v].begin()) return 0LL;
	r=prev(it)-vals[v].begin();
	ll res=0;
	for(int i=r;i>=0;i=(i&(i+1))-1) res+=fenw[v][i];
	return res;
}
ll Query(int&v,int l,int r,int ql,int qr){
	if(!v||l>r||l>qr||r<ql)return 0;
	if(ql<=l&&r<=qr)return Get(v,qr)-Get(v,ql-1);
	int mid=l+r>>1;
	return Query(ls[v],l,mid,ql,qr)+Query(rs[v],mid+1,r,ql,qr);
}
void Insert1(int&v,int l,int r,int ql,int qr){
	if(!v||l>r||l>qr||r<ql)return;
	if(ql<=l&&r<=qr){
		vals[v].push_back(qr);
		vals[v].push_back(ql-1);
		return;
	}
	int mid=l+r>>1;
	Insert1(ls[v],l,mid,ql,qr);
	Insert1(rs[v],mid+1,r,ql,qr);
}
void Build(int v,int l,int r) {
	if(!v)return;
	sort(vals[v].begin(),vals[v].end());
	vals[v].erase(unique(vals[v].begin(),vals[v].end()),vals[v].end());
	fenw[v].resize(vals[v].size());
//	printf("%d %d %d %d\n",v,l,r,fenw[v].size());
	int mid=l+r>>1;
	Build(ls[v],l,mid);
	Build(rs[v],r,mid);
}
int _a[N],t[N],p[N],x[N],l[N],r[N];
int main(){
	scanf("%i%i",&n,&q);
	for(int i=1;i<=n;i++)scanf("%i",&a[i]),_a[i]=a[i];
	for(int i=1;i<=n;i++){
		int prv=0;
		if(!pos[a[i]].empty())prv=*prev(pos[a[i]].end());
//		printf("%i %i\n",i,prv);
		//Update(root[0],0,n,i,prv,i-prv);
		Insert0(root[0],0,n,i,prv,i-prv);
		pos[a[i]].insert(i);
	}
	for(int i=1;i<=q;i++){
		scanf("%i",&t[i]);
		if(t[i]==1)scanf("%i%i",&p[i],&x[i]);
		else scanf("%i%i",&l[i],&r[i]);
	}
	for(int i=1;i<=q;i++){
		if(t[i]==1){
			if(a[p[i]]==x[i])continue;
			{
				int prv=0;
				auto it=pos[a[p[i]]].lower_bound(p[i]);
				if (it!=pos[a[p[i]]].begin()) prv=*prev(it);
				Insert0(root[0],0,n,p[i],prv,-(p[i]-prv));
			}
			{
				auto it=pos[a[p[i]]].lower_bound(p[i]+1);
				if(it!=pos[a[p[i]]].end()){
					int idx=*it;
					Insert0(root[0],0,n,idx,p[i],-(idx-p[i]));
					int prv=0;
					it=prev(it);
					if(it!=pos[a[p[i]]].begin())prv=*prev(it);
					Insert0(root[0],0,n,idx,prv,idx-prv);
				}
			}
			pos[a[p[i]]].erase(p[i]);
			a[p[i]]=x[i];
			{
				auto it=pos[x[i]].lower_bound(p[i]+1);
				if(it!=pos[x[i]].end()){
					int idx=*it;
					int prv=0;
					if(it!=pos[x[i]].begin())prv=*prev(it);
					Insert0(root[0],0,n,idx,prv,-(idx-prv));
					Insert0(root[0],0,n,idx,p[i],idx-p[i]);
				}
			}
			{
				auto it=pos[x[i]].lower_bound(p[i]);
				int prv=0;
				if(it!=pos[x[i]].begin())prv=*prev(it);
				Insert0(root[0],0,n,p[i],prv,p[i]-prv);
 			}
			pos[x[i]].insert(p[i]);
		}else{
			Insert1(root[0],0,n,l[i],r[i]);
		}
	}
	Build(root[0],1,n);
	for(int i=1;i<=n;i++)pos[i].clear(),a[i]=_a[i];
	for(int i=1;i<=n;i++){
		int prv=0;
		if(!pos[a[i]].empty())prv=*prev(pos[a[i]].end());
//		printf("%i %i\n",i,prv);
		Update(root[0],0,n,i,prv,i-prv);
		pos[a[i]].insert(i);
	}
	for(int i=1;i<=q;i++){
		if(t[i]==1){
			if(a[p[i]]==x[i])continue;
			{
				int prv=0;
				auto it=pos[a[p[i]]].lower_bound(p[i]);
				if (it!=pos[a[p[i]]].begin()) prv=*prev(it);
				Update(root[0],0,n,p[i],prv,-(p[i]-prv));
			}
			{
				auto it=pos[a[p[i]]].lower_bound(p[i]+1);
				if(it!=pos[a[p[i]]].end()){
					int idx=*it;
					Update(root[0],0,n,idx,p[i],-(idx-p[i]));
					int prv=0;
					it=prev(it);
					if(it!=pos[a[p[i]]].begin())prv=*prev(it);
					Update(root[0],0,n,idx,prv,idx-prv);
				}
			}
			pos[a[p[i]]].erase(p[i]);
			a[p[i]]=x[i];
			{
				auto it=pos[x[i]].lower_bound(p[i]+1);
				if(it!=pos[x[i]].end()){
					int idx=*it;
					int prv=0;
					if(it!=pos[x[i]].begin())prv=*prev(it);
					Update(root[0],0,n,idx,prv,-(idx-prv));
					Update(root[0],0,n,idx,p[i],idx-p[i]);
				}
			}
			{
				auto it=pos[x[i]].lower_bound(p[i]);
				int prv=0;
				if(it!=pos[x[i]].begin())prv=*prev(it);
				Update(root[0],0,n,p[i],prv,p[i]-prv);
 			}
			pos[x[i]].insert(p[i]);
		}else{
			printf("%lld\n",Query(root[0],0,n,l[i],r[i]));
		}
	}

	return 0;
}
/*
7 2
1 2 3 1 3 2 1
2 3 7
2 1 3
*/