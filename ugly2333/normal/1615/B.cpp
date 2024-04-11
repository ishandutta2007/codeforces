//CF1615B
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
const int N = 222222;
int n,m=20,f[N][22];
int main()
{
	int T,i,j,s,l,r;
	n=200005;
	for(i=1;i<=n;i++){
		for(j=0;j<m;j++)
			f[i][j]=f[i-1][j]+((i>>j)&1);
	}
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&l,&r);
		l--;
		s=0;
		for(i=0;i<m;i++)
			s=max(s,f[r][i]-f[l][i]);
		printf("%d\n",r-l-s);
	}
	return 0;
}