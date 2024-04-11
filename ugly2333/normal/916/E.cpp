//CF 916E
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
const int N = 111111;
const int Q = 22;
int n,d[N],q=20,f[N][Q];
int tt,tin[N],tout[N];
vector<int> v[N];
void dfs(int u,int fa){
	int i,sz=v[u].size();
	d[u]=d[fa]+1;
	f[u][0]=fa;
	tin[u]=++tt;
	for(i=0;i<sz;i=i+1)
		if(v[u][i]!=fa)
			dfs(v[u][i],u);
	tout[u]=tt;
}
int lca(int x,int y){
	if(d[x]<d[y])
		swap(x,y);
	int j;
	for(j=q;j>=0;j=j-1)
		if(d[f[x][j]]>=d[y])
			x=f[x][j];
	if(x==y)
		return x;
	for(j=q;j>=0;j=j-1)
		if(f[x][j]!=f[y][j])
			x=f[x][j],y=f[y][j];
	return f[x][0];
}
int lst(int x,int y){
	int j;
	for(j=q;j>=0;j=j-1)
		if(d[f[x][j]]>d[y])
			x=f[x][j];
	return x;
}
LL T[N<<2],W[N<<2];
void modify(int L,int R,LL V,int k=1,int l=1,int r=n){
	if(L<=l&&r<=R){
		W[k]+=V;
		T[k]+=V*(r-l+1);
		return;
	}
	int h=l+r>>1;
	LL w=W[k];
	if(w){
		W[k<<1]+=w;
		T[k<<1]+=w*(h-l+1);
		W[k<<1|1]+=w;
		T[k<<1|1]+=w*(r-h);
		W[k]=0;
	}
	if(L<=h)
		modify(L,R,V,k<<1,l,h);
	if(h<R)
		modify(L,R,V,k<<1|1,h+1,r);
	T[k]=T[k<<1]+T[k<<1|1];
}
LL query(int L,int R,int k=1,int l=1,int r=n){
	if(L<=l&&r<=R)
		return T[k];
	int h=l+r>>1;
	LL res=0,w=W[k];
	if(w){
		W[k<<1]+=w;
		T[k<<1]+=w*(h-l+1);
		W[k<<1|1]+=w;
		T[k<<1|1]+=w*(r-h);
		W[k]=0;
	}
	if(L<=h)
		res+=query(L,R,k<<1,l,h);
	if(h<R)
		res+=query(L,R,k<<1|1,h+1,r);
	return res;
}
int a[N];
int main()
{
	int nq,i,j,k,x,y,z,rt,xx,yy;
	scanf("%d%d",&n,&nq);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i);
	for(i=1;i<n;i=i+1){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	rt=1;
	dfs(rt,0);
	for(j=1;j<=q;j=j+1)
		for(i=1;i<=n;i=i+1)
			f[i][j]=f[f[i][j-1]][j-1];
	for(i=1;i<=n;i=i+1)
		modify(tin[i],tin[i],a[i]);
	while(nq--){
		scanf("%d%d",&i,&x);
		if(i==1)
			rt=x;
		if(i==3){
			if(x==rt)
				cout<<query(1,n)<<endl;
			else{
				if(lca(rt,x)==x){
					x=lst(rt,x);
					cout<<query(1,n)-query(tin[x],tout[x])<<endl;
				}
				else
					cout<<query(tin[x],tout[x])<<endl;
			}
		}
		if(i==2){
			scanf("%d%d",&y,&z);
			i=lca(x,y);
			j=lca(rt,i);
			if(i==j){
				xx=lca(rt,x),yy=lca(rt,y);
				modify(1,n,z);
				if(xx!=rt&&yy!=rt){
					i=xx+yy-i;
					i=lst(rt,i);
					modify(tin[i],tout[i],-z);
				}
			}
			else
				modify(tin[i],tout[i],z);
		}
	}
	return 0;
}