//CF1656A
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
	int T,n,i,mx,mn,j,k,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		mx=0,mn=1e9+1;
		for(i=1;i<=n;i++){
			scanf("%d",&x);
			if(x>mx)
				mx=x,j=i;
			if(x<mn)
				mn=x,k=i;
		}
		printf("%d %d\n",j,k);
	}
	return 0;
}