//CF1558A
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
int f[N];
int main()
{
	int T,i,a,b,n,x,y;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&a,&b);
		n=a+b;
		y=n/2;
		x=n-y;
		for(i=0;i<=a;i++)
			if(i<=x&&a-i<=y)
				f[x-i+a-i]=1;
		swap(x,y);
		for(i=0;i<=a;i++)
			if(i<=x&&a-i<=y)
				f[x-i+a-i]=1;
		x=0;
		for(i=0;i<=n;i++)
			if(f[i])
				x++;
		printf("%d\n",x);
		for(i=0;i<=n;i++)
			if(f[i])
				printf("%d ",i),f[i]=0;
		printf("\n");
	}
	return 0;
}