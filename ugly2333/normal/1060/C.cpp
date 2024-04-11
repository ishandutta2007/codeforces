//
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
const int N = 2222;
const int inf = 2e9+N;
int n,m,a[N],b[N],aa[N],bb[N];
LL k;
int main()
{
	int i,j,x;
	cin>>n>>m;
	for(i=1;i<=n;i=i+1)
		cin>>a[i],aa[i]=inf;
	for(i=1;i<=m;i=i+1)
		cin>>b[i],bb[i]=inf;
	for(i=1;i<=n;i=i+1){
		x=0;
		for(j=i;j<=n;j=j+1){
			x+=a[j];
			aa[j-i+1]=min(aa[j-i+1],x);
		}
	}
	for(i=1;i<=m;i=i+1){
		x=0;
		for(j=i;j<=m;j=j+1){
			x+=b[j];
			bb[j-i+1]=min(bb[j-i+1],x);
		}
	}
	cin>>k;
	x=0;
	for(i=1;i<=n;i=i+1)
		for(j=1;j<=m;j=j+1)
			if((LL)aa[i]*bb[j]<=k)
				x=max(x,i*j);
	cout<<x;
	return 0;
}