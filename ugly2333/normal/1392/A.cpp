//CF1392A
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
int main()
{
	int T,n,i,o,x,y;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		x=2e9,y=-1;
		for(i=1;i<=n;i=i+1){
			scanf("%d",&o);
			x=min(x,o);
			y=max(y,o);
		}
		if(x==y)
			printf("%d\n",n);
		else
			printf("1\n");
	}
	return 0;
}