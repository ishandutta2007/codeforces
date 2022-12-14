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
int a[max_n+1][max_m+1],t[max_n*max_m+1];
il void test(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j){
			scanf("%d",a[i]+j);
			t[a[i][j]]=i;
		}
	for(int i=1,x; i<=n; ++i){
		scanf("%d",&x);
		int r=t[x];
		for(int j=1; j<=m; ++j)
			printf("%d ",a[r][j]);
		putchar('\n');
	}
	for(int i=2; i<=m; ++i)
		for(int j=1; j<=n; ++j,scanf("%*d"));
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}