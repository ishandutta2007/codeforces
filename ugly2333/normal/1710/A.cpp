//CF1710A
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
LL n,m,k,a[N];
int main()
{
	LL T,i,x,y;
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld%lld",&n,&m,&k);
		for(i=1;i<=k;i++)
			scanf("%lld",a+i);
		x=0;
		for(i=1;i<=k;i++)
			if(a[i]/n>=2)
				x+=a[i]/n;
		if(x>=m){
			x=0;
			if(m%2==0)
				x=1;
			for(i=1;i<=k;i++)
				if(a[i]/n>=3)
					x=1;
			if(x){
				printf("Yes\n");
				continue;
			}
		}
		y=0;
		for(i=1;i<=k;i++)
			if(a[i]/m>=2)
				y+=a[i]/m;
		if(y>=n){
			x=0;
			if(n%2==0)
				x=1;
			for(i=1;i<=k;i++)
				if(a[i]/m>=3)
					x=1;
			if(x){
				printf("Yes\n");
				continue;
			}
		}
		printf("No\n");
	}
	return 0;
}