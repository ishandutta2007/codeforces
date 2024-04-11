//CF1726A
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
int n,a[N];
int main()
{
	int T,i,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		x=a[n]-a[1];
		for(i=1;i<n;i++)
			x=max(x,a[i]-a[i+1]);
		for(i=2;i<=n;i++)
			x=max(x,a[i]-a[1]);
		for(i=1;i<n;i++)
			x=max(x,a[n]-a[i]);
		printf("%d\n",x);
	}
	return 0;
}