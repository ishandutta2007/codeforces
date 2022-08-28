//CF1677A
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
const int N = 5555;
int n,a[N],b[N][N];
int main()
{
	int T,i,j;
	LL s;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",a+i),b[i][a[i]]=1;
		for(i=1;i<=n+1;i++)
			for(j=1;j<=n;j++)
				b[i][j]+=b[i][j-1];
		for(i=1;i<=n+1;i++)
			for(j=1;j<=n;j++)
				b[i][j]+=b[i-1][j];
		s=0;
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
				s+=b[i-1][a[j]-1]*(a[i]-1-b[j][a[i]-1]);
		printf("%lld\n",s);
		for(i=0;i<=n+1;i++)
			for(j=0;j<=n+1;j++)
				b[i][j]=0;
	}
	return 0;
}