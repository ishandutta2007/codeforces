//CF 827D
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
typedef double DB;
const int N = 222222;
const int W = 22;
const int inf = 2e9;
int n,r[N],d[N],c[N],f[N][W],s[N][W],t[N][W];
int m,x[N],y[N],z[N],ans[N];
vector<int> v[N];
priority_queue<pair<int,int> > Q;
int lca(int xx,int yy){
	int j;
	if(d[xx]<d[yy])
		swap(xx,yy);
	for(j=20;j>=0;j=j-1)
		if(d[f[xx][j]]>=d[yy])
			xx=f[xx][j];
	if(xx==yy)
		return xx;
	for(j=20;j>=0;j=j-1)
		if(f[xx][j]!=f[yy][j])
			xx=f[xx][j],yy=f[yy][j];
	return f[xx][0];
}
int main()
{
	int i,j,l,xx,yy;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i=i+1){
		scanf("%d%d%d",x+i,y+i,z+i);
		if(x[i]>y[i])
			swap(x[i],y[i]);
		v[x[i]].push_back(i);
		v[y[i]].push_back(i);
		if(x[i]==1)
			Q.push(make_pair(-z[i],i));
	}
	for(i=0;i<=n;i=i+1)
		for(j=0;j<=20;j=j+1)
			t[i][j]=inf;
	r[1]=1;
	d[1]=1;
	while(!Q.empty()){
		i=Q.top().second;
		Q.pop();
		xx=x[i],yy=y[i];
		if(r[yy]){
			l=lca(xx,yy);
			for(j=20;j>=0;j=j-1)
				if(d[f[xx][j]]>=d[l]){
					ans[i]=max(ans[i],s[xx][j]);
					t[xx][j]=min(t[xx][j],z[i]);
					xx=f[xx][j];
				}
			for(j=20;j>=0;j=j-1)
				if(d[f[yy][j]]>=d[l]){
					ans[i]=max(ans[i],s[yy][j]);
					t[yy][j]=min(t[yy][j],z[i]);
					yy=f[yy][j];
				}
		}
		else{
			r[yy]=1;
			d[yy]=d[xx]+1;
			c[yy]=i;
			f[yy][0]=xx;
			s[yy][0]=z[i];
			for(j=1;j<=20;j=j+1){
				l=f[yy][j-1];
				f[yy][j]=f[l][j-1];
				s[yy][j]=max(s[yy][j-1],s[l][j-1]);
			}
			j=v[yy].size();
			while(j--){
				l=v[yy][j];
				if(!r[x[l]+y[l]-yy]){
					if(y[l]==yy)
						swap(x[l],y[l]);
					Q.push(make_pair(-z[l],l));
				}
			}
		}
	}
	for(j=20;j;j=j-1)
		for(i=1;i<=n;i=i+1){
			l=f[i][j-1];
			t[i][j-1]=min(t[i][j-1],t[i][j]);
			t[l][j-1]=min(t[l][j-1],t[i][j]);
		}
	for(i=2;i<=n;i=i+1)
		ans[c[i]]=t[i][0];
	for(i=1;i<=m;i=i+1){
		if(ans[i]==inf)
			ans[i]=0;
		printf("%d ",ans[i]-1);
	}
	return 0;
}