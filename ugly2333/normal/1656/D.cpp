//CF1656D
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
	int T;
	LL x,y,z;
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&x);
		x*=2;
		y=1;
		while(x%2==0){
			y*=2;
			x/=2;
		}
		if(x!=1)
			printf("%lld\n",min(x,y));
		else
			printf("-1\n");
	}
	return 0;
}