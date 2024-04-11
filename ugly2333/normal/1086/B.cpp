//CF1086B
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
int n,s,a[N];
int main()
{
	int i,x,y;
	scanf("%d%d",&n,&s);
	if(n==2){
		printf("%.9lf",(DB)s);
		return 0;
	}
	for(i=1;i<n;i=i+1){
		scanf("%d%d",&x,&y);
		a[x]++;
		a[y]++;
	}
	x=0;
	for(i=1;i<=n;i=i+1)
		if(a[i]==1)
			x++;
	printf("%.9lf",(DB)s*2/x);
	return 0;
}