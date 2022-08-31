//CF1552B
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
const int N = 55555;
int n,m=5,a[N][6];
int mx(int x,int y){
	int i,o=0;
	for(i=1;i<=5;i++)
		if(a[x][i]<a[y][i])
			o++;
	if(o>=3)
		return x;
	return y;
}
int main()
{
	int T,i,j,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			for(j=1;j<=5;j++)
				scanf("%d",a[i]+j);
		x=1;
		for(i=2;i<=n;i++)
			x=mx(x,i);
		j=1;
		for(i=1;i<=n;i++)
			if(x!=i&&mx(x,i)!=x)
				j=0;
		if(!j)
			x=-1;
		printf("%d\n",x);
	}
	return 0;
}