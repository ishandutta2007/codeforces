#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_n 500
#define max_m 500
#define max_k 20
int f[(max_k>>1)+1][max_n+1][max_m+1];
int a[max_n+1][max_m+1],b[max_n+1][max_m+1];
void minify(int&x,ci y){
	y<x&&(x=y);
}
il void test(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<m; ++j)
			scanf("%d",a[i]+j);
	for(int i=1; i<n; ++i)
		for(int j=1; j<=m; ++j)
			scanf("%d",b[i]+j);
	if((k&1)){
		for(int i=1; i<=n; ++i,puts(""))
			for(int j=1; j<=m; ++j)
				printf("-1 ");
		return;
	}
	memset(f[0],0,sizeof(f[0]));
	for(int l=1,ed=k>>1; l<=ed; ++l)
		for(int i=1; i<=n; ++i)
			for(int j=1; j<=m; ++j){
				int ret=2147483647;
				if(i>1)
					minify(ret,f[l-1][i-1][j]+b[i-1][j]*2);
				if(j>1)
					minify(ret,f[l-1][i][j-1]+a[i][j-1]*2);
				if(i<n)
					minify(ret,f[l-1][i+1][j]+b[i][j]*2);
				if(j<m)
					minify(ret,f[l-1][i][j+1]+a[i][j]*2);
				f[l][i][j]=ret;
			}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j)
			printf("%d ",f[k>>1][i][j]);
		puts("");
	}
}
int main(){
	test();
//	int t;
//	for(scanf("%d",&t); t; test(),--t);
	return 0;
}