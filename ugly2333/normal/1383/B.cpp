//CF1383B
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
	int T,i,x,y,z;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		x=0;
		for(i=1;i<=n;i=i+1)
			scanf("%d",a+i),x^=a[i];
		if(x==0){
			printf("DRAW\n");
			continue;
		}
		for(y=(1<<30);y>x;y>>=1);
		z=0;
		for(i=1;i<=n;i=i+1)
			if(a[i]&y)
				z++;
		x=(z-1)/2,y=n-z;
		if(x%2==1&&y%2==0)
			printf("LOSE\n");
		else
			printf("WIN\n");
	}
	return 0;
}