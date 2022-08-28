//CF 901C
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
const int N = 333333;
int n,m,a[N];
vector<int> v[N];
int vis[N],s[N],ins[N],ss;
void jh(int u){
	int mx,mn,i;
	mx=0,mn=n+1;
	i=ss;
	while(1){
		mx=max(mx,s[i]);
		mn=min(mn,s[i]);
		if(s[i]==u)
			break;
		i--;
	}
	if(a[mn]>mx-1)
		a[mn]=mx-1;
}
void dfs(int u,int fa=-1){
	int i,sz,x;
	vis[u]=1;
	s[++ss]=u,ins[u]=1;
	sz=v[u].size();
	for(i=0;i<sz;i=i+1){
		x=v[u][i];
		if(x==fa)
			continue;
		if(ins[x])
			jh(x);
		if(!vis[x])
			dfs(x,u);
	}
	s[ss--]=0,ins[u]=0;
}
LL T[N<<2],h[N<<2];
void modify(int L,int R,int k=1,int l=1,int r=n){
	//cout<<"modify"<<L<<R<<k<<l<<r<<T[k]<<endl;
	if(L<=l&&r<=R){
		T[k]+=r-l+1;
		h[k]++;
		return;
	}
	if(r<L||R<L||R<l||r<=l)
		return;
	int x=l+r>>1;
	if(h[k]){
		T[k<<1]+=h[k]*(x-l+1);
		h[k<<1]+=h[k];
		T[k<<1|1]+=h[k]*(r-x);
		h[k<<1|1]+=h[k];
		h[k]=0;
	}
	if(L<=x)
		modify(L,R,k<<1,l,x);
	if(x<R)
		modify(L,R,k<<1|1,x+1,r);
	T[k]=T[k<<1]+T[k<<1|1];
}
LL query(int L,int R,int k=1,int l=1,int r=n){
	//cout<<"query"<<L<<R<<k<<l<<r<<T[k]<<endl;
	if(L<=l&&r<=R)
		return T[k];
	if(r<L||R<L||R<l||r<=l)
		return 0;
	int x=l+r>>1;
	if(h[k]){
		T[k<<1]+=h[k]*(x-l+1);
		h[k<<1]+=h[k];
		T[k<<1|1]+=h[k]*(r-x);
		h[k<<1|1]+=h[k];
		h[k]=0;
	}
	LL o=0;
	if(L<=x)
		o+=query(L,R,k<<1,l,x);
	if(x<R)
		o+=query(L,R,k<<1|1,x+1,r);
	return o;
}
vector<pair<int,int> > q[N];
LL ans[N];
int main()
{
	int i,j,x,y,z,qq;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i=i+1)
		a[i]=n;
	for(i=1;i<=m;i=i+1){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(i=1;i<=n;i=i+1)
		if(!vis[i])
			dfs(i);
	for(i=n-1;i>=1;i=i-1)
		a[i]=min(a[i],a[i+1]);
	scanf("%d",&qq);
	for(i=1;i<=qq;i=i+1){
		scanf("%d%d",&x,&y);
		q[x].push_back(make_pair(y,i));
	}
	for(i=n;i>=1;i=i-1){
		//cout<<i<<' '<<a[i]<<endl;
		modify(i,a[i]);
		z=q[i].size();
		//cout<<z<<endl;
		for(j=0;j<z;j=j+1){
			y=q[i][j].first;
			ans[q[i][j].second]=query(1,y);
		}
	}
	for(i=1;i<=qq;i=i+1)
		cout<<ans[i]<<endl;
	return 0;
}