//CF1179B
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
	int n,m,o,i,j,x,y;
	scanf("%d%d",&n,&m);
	i=1,j=1,x=n,y=m;
	for(o=2;o<=n*m;o=o+2){
		printf("%d %d\n%d %d\n",i,j,x,y);
		j++;
		if(j>m)
			i++,j=1;
		y--;
		if(y<1)
			x--,y=m;
	}
	if(n*m%2)
		printf("%d %d\n",i,j);
	return 0;
}