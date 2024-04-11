//CF1010A
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
const int N = 1111;
int n,m,a[N],b[N];
int ok(DB x){
	int i;
	x+=m;
	for(i=1;i<=n;i=i+1)
		x-=x/a[i],x-=x/b[i+1];
	return (x>=m);
}
int main()
{
	int i;
	DB l,r,h;
	cin>>n>>m;
	for(i=1;i<=n;i=i+1)
		cin>>a[i];
	for(i=1;i<=n;i=i+1)
		cin>>b[i];
	a[n+1]=a[1],b[n+1]=b[1];
	l=1,r=1e9+2;
	while(r-l>=1e-9){
		h=(l+r)/2;
		if(ok(h))
			r=h;
		else
			l=h;
	}
	if(l>1e9+1)
		l=-1;
	printf("%.9lf",l);
	return 0;
}