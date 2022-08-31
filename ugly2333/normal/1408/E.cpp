//CF1408E
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
int m,n,a[N],b[N];
int e,x[N],y[N],f[N];
pair<int,int> p[N];
LL ans;
void adde(int u,int v,int w){
	e++;
	x[e]=u,y[e]=v;
	p[e]=make_pair(-w,e);
}
int fnd(int x){
	if(f[x]==x)
		return x;
	return f[x]=fnd(f[x]);
}
int main()
{
	int i,j,k;
	scanf("%d%d",&m,&n);
	for(i=1;i<=m;i=i+1)
		scanf("%d",a+i);
	for(i=1;i<=n;i=i+1)
		scanf("%d",b+i);
	for(i=1;i<=m;i=i+1){
		scanf("%d",&j);
		while(j--){
			scanf("%d",&k);
			adde(i,m+k,a[i]+b[k]);
		}
	}
	sort(p+1,p+e+1);
	for(i=1;i<=m+n;i=i+1)
		f[i]=i;
	for(i=1;i<=e;i=i+1){
		k=p[i].second;
		if(fnd(x[k])==fnd(y[k])){
			ans+=-p[i].first;
			continue;
		}
		f[fnd(x[k])]=fnd(y[k]);
	}
	cout<<ans;
	return 0;
}