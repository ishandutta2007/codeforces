//CF1684A
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
	int T,n,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(n<=99)
			x=n%10;
		else{
			x=10;
			while(n){
				x=min(x,n%10);
				n/=10;
			}
		}
		printf("%d\n",x);
	}
	return 0;
}