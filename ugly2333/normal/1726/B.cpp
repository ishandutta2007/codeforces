//CF1726B
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
int n,m;
int main()
{
	int T,i;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		if(n>m){
			printf("No\n");
			continue;
		}
		if(n==m){
			printf("Yes\n");
			for(i=1;i<=n;i++)
				printf("1 ");
			printf("\n");
			continue;
		}
		if(n%2==1){
			printf("Yes\n");
			for(i=1;i<=n-1;i++)
				printf("1 "),m--;
			printf("%d\n",m);
			continue;
		}
		if(m%2==1){
			printf("No\n");
			continue;
		}
		printf("Yes\n");
		for(i=1;i<=n-2;i++)
			printf("1 "),m--;
		printf("%d %d\n",m/2,m/2);
	}
	return 0;
}