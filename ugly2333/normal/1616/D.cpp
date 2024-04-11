//CF1616D
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
int n,a[N],f[N][4];
int main()
{
	int T,i,j,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		scanf("%d",&x);
		for(i=1;i<=n;i++)
			a[i]-=x;
		memset(f,0,sizeof(f));
		f[0][0]=N;
		for(i=1;i<=n+1;i++){
			for(j=0;j<=3;j++)
				f[i][0]=max(f[i][0],f[i-1][j]);
			for(j=0;j<=3&&j<=i-1;j++){
				if(j>=1&&a[i]+a[i-1]<0)
					continue;
				if(j>=2&&a[i]+a[i-1]+a[i-2]<0)
					continue;
				f[i][min(j+1,3)]=max(f[i][min(j+1,3)],f[i-1][j]+1);
			}
		}
		printf("%d\n",f[n+1][0]-N);
	}
	return 0;
}