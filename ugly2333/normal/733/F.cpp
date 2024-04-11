//CF 733F
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
const int R = 22;
const int inf = 2e9;
int n,d[N],q=20,f[N][R],g[N][R],h[N][R];
int lca(int x,int y){
	int i,r=0,t;
	if(d[x]<d[y])
		swap(x,y);
	for(i=q;i>=0;i=i-1)
		if(d[f[x][i]]>=d[y]){
			if(r<g[x][i])
				r=g[x][i],t=h[x][i];
			x=f[x][i];
		}
	if(x==y)
		return t;
	for(i=q;i>=0;i=i-1)
		if(f[x][i]!=f[y][i]){
			if(r<g[x][i])
				r=g[x][i],t=h[x][i];
			if(r<g[y][i])
				r=g[y][i],t=h[y][i];
			x=f[x][i],y=f[y][i];
		}
	if(r<g[x][0])
		r=g[x][0],t=h[x][0];
	if(r<g[y][0])
		r=g[y][0],t=h[y][0];
	return t;
}
int m,x[N],y[N],w[N],c[N],a[N];
vector<int> v[N];
priority_queue<pair<int,int> > Q;
int s,ans,ansi,ansj;
LL ss;
int main()
{
	int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i=i+1)
		scanf("%d",w+i);
	for(i=1;i<=m;i=i+1)
		scanf("%d",c+i);
	for(i=1;i<=m;i=i+1){
		scanf("%d%d",x+i,y+i);
		v[x[i]].push_back(i);
		v[y[i]].push_back(i);
	}
	scanf("%d",&s);
	d[1]=1;
	for(j=v[1].size()-1;j>=0;j=j-1){
		k=v[1][j];
		Q.push(make_pair(-w[k],k));
	}
	while(!Q.empty()){
		i=Q.top().second;
		Q.pop();
		if(!d[x[i]])
			swap(x[i],y[i]);
		if(!d[y[i]]){
			a[i]=1;
			ss+=w[i];
			if(ans<=s/c[i])
				ans=s/c[i],ansi=i,ansj=i;
			d[y[i]]=d[x[i]]+1;
			f[y[i]][0]=x[i];
			g[y[i]][0]=w[i];
			h[y[i]][0]=i;
			for(j=1;j<=q;j=j+1){
				k=f[y[i]][j-1];
				f[y[i]][j]=f[k][j-1];
				g[y[i]][j]=g[y[i]][j-1],h[y[i]][j]=h[y[i]][j-1];
				if(g[y[i]][j]<g[k][j-1])
					g[y[i]][j]=g[k][j-1],h[y[i]][j]=h[k][j-1];
			}
			for(j=v[y[i]].size()-1;j>=0;j=j-1){
				k=v[y[i]][j];
				if(!d[x[k]+y[k]-y[i]])
					Q.push(make_pair(-w[k],k));
			}
		}
		else{
			j=lca(x[i],y[i]);
			if(ans<=s/c[i]+w[j]-w[i])
				ans=s/c[i]+w[j]-w[i],ansi=i,ansj=j;
		}
	}
	cout<<ss-ans<<endl;
	i=ansi,j=ansj;
	a[j]=0,a[i]=1,w[i]-=s/c[i];
	for(i=1;i<=m;i=i+1)
		if(a[i])
			cout<<i<<' '<<w[i]<<endl;
	return 0;
}