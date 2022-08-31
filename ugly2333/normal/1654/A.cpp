//CF1654A
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
int n,a[N];
int main()
{
	int T,x,i,k;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		sort(a+1,a+n+1);
		printf("%d\n",a[n-1]+a[n]);
	}
	return 0;
}