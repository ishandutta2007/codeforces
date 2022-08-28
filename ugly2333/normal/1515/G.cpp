//CF1515G
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 222222;
int n,m,x[N],y[N],z[N],b[N],f[N],w,a[N];
LL dh[N],de[N],g[N];
vector<int> v[N],h[N],r[N],e[N];
LL gcd(LL x,LL y){
	if(!y)
		return x;
	return gcd(y,x%y);
}
void dfsr(int u){
	if(b[u])
		return;
	b[u]=1;
	int i,x;
	for(i=0;i<r[u].size();i=i+1){
		x=r[u][i];
		dfsr(x);
	}
	a[++w]=u;
}
void dfsv(int u,int ff){
	if(f[u])
		return;
	f[u]=ff;
	int i,x;
	for(i=0;i<v[u].size();i=i+1){
		x=v[u][i];
		dfsv(x,ff);
	}
}
void dfsh(int u){
	int i,x;
	for(i=0;i<v[u].size();i=i+1){
		x=v[u][i];
		if(f[u]==f[x]&&dh[x]<0){
			dh[x]=dh[u]+h[u][i];
			dfsh(x);
		}
	}
}
void dfse(int u){
	int i,x;
	for(i=0;i<r[u].size();i=i+1){
		x=r[u][i];
		if(f[u]==f[x]&&de[x]<0){
			de[x]=de[u]+e[u][i];
			dfse(x);
		}
	}
}
int main()
{
	int i,o,p,q;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i=i+1){
		scanf("%d%d%d",x+i,y+i,z+i);
		v[x[i]].push_back(y[i]);
		h[x[i]].push_back(z[i]);
		r[y[i]].push_back(x[i]);
		e[y[i]].push_back(z[i]);
	}
	for(i=1;i<=n;i=i+1)
		dfsr(i);
	for(i=n;i>=1;i=i-1)
		dfsv(a[i],a[i]);
	for(i=1;i<=n;i=i+1)
		dh[i]=-1,de[i]=-1;
	for(i=1;i<=n;i=i+1){
		if(f[i]==i){
			dh[i]=0;
			dfsh(i);
			de[i]=0;
			dfse(i);
		}
	}
	for(i=1;i<=n;i=i+1){
		g[f[i]]=gcd(g[f[i]],dh[i]+de[i]);
	}
	for(i=1;i<=m;i=i+1){
		if(f[x[i]]!=f[y[i]])
			continue;
		o=f[x[i]];
		g[o]=gcd(g[o],dh[x[i]]+z[i]+de[y[i]]);
	}
	scanf("%d",&m);
	while(m--){
		scanf("%d%d%d",&i,&p,&q);
		q=gcd(g[f[i]],q);
		if(p%q==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}