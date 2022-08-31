//CF1621A
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
const int N = 111;
int n,m,a[N][N];
int main()
{
	int T,i,j;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		if(m*2-1>n){
			printf("-1\n");
		}
		else{
			memset(a,0,sizeof(a));
			for(i=1;i<=m*2-1;i+=2)
				a[i][i]=1;
			for(i=1;i<=n;i++){
				for(j=1;j<=n;j++){
					if(a[i][j])
						printf("R");
					else
						printf(".");
				}
				printf("\n");
			}
		}
	}
	return 0;
}