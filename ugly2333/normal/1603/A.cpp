//CF1603A
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
	int T,i,j,x,y;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		x=1;
		for(i=1;i<=n&&i<=50;i++){
			y=0;
			for(j=2;j<=i+1;j++)
				if(a[i]%j)
					y=1;
			x&=y;
		}
		if(x)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}