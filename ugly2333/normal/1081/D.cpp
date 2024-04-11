//CF1081D
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
const int N = 111111;
int n,m,k,a[N],f[N],g[N];
pair<int,pair<int,int> > p[N];
int fnd(int x){
	if(f[x]==x)
		return x;
	return f[x]=fnd(f[x]);
}
int main()
{
	int i,x,y,z;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=k;i=i+1)
		scanf("%d",&x),a[x]=1,g[x]=1;
	for(i=0;i<m;i=i+1){
		scanf("%d%d%d",&x,&y,&z);
		p[i]=make_pair(z,make_pair(x,y));
	}
	for(i=1;i<=n;i=i+1)
		f[i]=i;
	sort(p,p+m);
	for(i=0;i<m;i=i+1){
		z=p[i].first;
		x=p[i].second.first;
		y=p[i].second.second;
		x=fnd(x),y=fnd(y);
		if(x==y)
			continue;
		f[y]=x;
		g[x]+=g[y];
		if(g[x]==k)
			break;
	}
	for(i=1;i<=k;i=i+1)
		cout<<z<<' ';
	return 0;
}