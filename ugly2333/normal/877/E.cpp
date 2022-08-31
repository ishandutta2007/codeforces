//CF 877E
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int N = 222222;
vector<int> v[N];
int p[N],f[N];
int a[N],t,tin[N],tout[N];
int T[N*4],w[N*4];
void dfs(int u){
	tin[u]=++t;
	a[t]=u;
	int i,s,x;
	s=v[u].size();
	for(i=0;i<s;i=i+1){
		x=v[u][i];
		if(x==p[u])
			continue;
		dfs(x);
	}
	tout[u]=t;
}
void build(int k,int l,int r){
	if(l==r){
		T[k]=f[a[l]];
		return;
	}
	int md;
	md=(l+r)>>1;
	build(k<<1,l,md);
	build(k<<1|1,md+1,r);
	T[k]=T[k<<1]+T[k<<1|1];
}
void modify(int k,int l,int r,int L,int R){
	if(L==l&&R==r){
		w[k]^=1;
		T[k]=(r-l+1)-T[k];
		return;
	}
	int md;
	md=(l+r)>>1;
	if(w[k]){
		w[k<<1]^=1;
		T[k<<1]=(md-l+1)-T[k<<1];
		w[k<<1|1]^=1;
		T[k<<1|1]=(r-md)-T[k<<1|1];
		w[k]=0;
	}
	if(L<=md)
		modify(k<<1,l,md,L,min(md,R));
	if(md<R)
		modify(k<<1|1,md+1,r,max(L,md+1),R);
	T[k]=T[k<<1]+T[k<<1|1];
}
int query(int k,int l,int r,int L,int R){
	//cout<<k<<l<<r<<L<<R<<endl;
	if(L==l&&R==r)
		return T[k];
	int md,res;
	md=(l+r)>>1;
	if(w[k]){
		w[k<<1]^=1;
		T[k<<1]=(md-l+1)-T[k<<1];
		w[k<<1|1]^=1;
		T[k<<1|1]=(r-md)-T[k<<1|1];
		w[k]=0;
	}
	res=0;
	if(L<=md)
		res+=query(k<<1,l,md,L,min(md,R));
	if(md<R)
		res+=query(k<<1|1,md+1,r,max(L,md+1),R);
	T[k]=T[k<<1]+T[k<<1|1];
	return res;
}
int main()
{
	int n,q,i;
	char ch[11];
	scanf("%d",&n);
	p[1]=0;
	for(i=2;i<=n;i=i+1){
		scanf("%d",p+i);
		v[p[i]].push_back(i);
	}
	for(i=1;i<=n;i=i+1)
		scanf("%d",f+i);
	t=0;
	dfs(1);
	build(1,1,n);
	scanf("%d",&q);
	while(q--){
		scanf("%s%d",&ch,&i);
		//cout<<tin[i]<<tout[i]<<endl;
		if(ch[0]=='p')
			modify(1,1,n,tin[i],tout[i]);
		else
			cout<<query(1,1,n,tin[i],tout[i])<<endl;
	}
	return 0;
}