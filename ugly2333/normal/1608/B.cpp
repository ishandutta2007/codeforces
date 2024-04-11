//CF1608B
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
int n,a,b,f[N];
int main()
{
	int T,i,x,y,z;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&a,&b);
		if(abs(a-b)>1||a+b>n-2){
			printf("-1\n");
			continue;
		}
		x=1,y=n;
		z=(a>b);
		for(i=1;i<=n;i++){
			if(z)
				f[i]=x,x++;
			else
				f[i]=y,y--;
			if(i<=a+b)
				z^=1;
		}
		for(i=1;i<=n;i++)
			printf("%d ",f[i]);
		printf("\n");
	}
	return 0;
}