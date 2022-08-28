//CF1442A
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
	int T,n,i,x,y,z,f;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		f=1;
		x=1e7,y=0;
		for(i=1;i<=n;i=i+1){
			scanf("%d",&z);
			if(z<y)
				f=0;
			if(z-y<=x)
				x=z-y;
			else
				y=z-x;
		}
		if(f)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}