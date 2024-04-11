#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int p[1000020],c,d[1020][1020];
int n,k,v[1020],x[1020],y[1020];
vector<int>a[1020];
int dfs(int x,int k)
{
	if(x==n)
		return 1;
	if(v[x])
		return dfs(x+1,k);
	fe(i,a[x])
		k-=!v[*i]++;
	int u=k;
	if(k>=0&&dfs(x+1,k))
		return 1;
	fe(i,a[x])
		k+=!--v[*i];
	v[x]=1;
	if(--k>=0&&k>u&&dfs(x+1,k))
		return 1;
	v[x]=0;
	return 0;
}
int ok(int x)
{
	fr(i,n)
		v[i]=0,a[i].clear();
	fr(i,n)
		fr(j,n)
			if(d[i][j]>x)
				a[i].push_back(j);
	return dfs(0,k);
}
int main()
{
	scanf("%d%d",&n,&k);
	fr(i,n)
		scanf("%d%d",x+i,y+i);
	fr(i,n)
		fr(j,i)
			p[c++]=d[i][j]=d[j][i]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
	p[c++]=0;
	sort(p,p+c);
	c=unique(p,p+c)-p;
	int l=-1,r=c,m;
	for(;l<r-1;)
		m=l+r>>1,(ok(p[m])?r:l)=m;
	ok(p[r]);
	fr(i,n)
		if(v[i])
			printf("%d ",i+1),k--;
	fr(i,n)
		if(k&&!v[i])
			printf("%d ",i+1),k--;
	return 0;
}