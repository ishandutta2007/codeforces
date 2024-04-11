//CF1179A
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
const int N = 666666;
int n,q,a[N],he,ta,m,b[N],c[N];
int main()
{
	int i,x;
	LL o;
	scanf("%d%d",&n,&q);
	x=-1;
	for(i=1;i<=n;i=i+1){
		scanf("%d",a+i);
		x=max(x,a[i]);
	}
	he=1,ta=n+1;
	while(a[he]!=x){
		m++;
		b[m]=a[he],c[m]=a[he+1];
		if(b[m]>c[m])
			a[++he]=b[m],a[ta++]=c[m];
		else
			a[++he]=c[m],a[ta++]=b[m];
	}
	while(q--){
		scanf("%lld",&o);
		if(o<=m)
			printf("%d %d\n",b[o],c[o]);
		else{
			o-=m+1;
			o%=(n-1);
			printf("%d %d\n",x,a[he+o+1]);
		}
	}
	return 0;
}