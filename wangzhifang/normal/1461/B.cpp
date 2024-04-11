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
int a[max_n+1][max_m+1];
il void test(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i){
		scanf("\n");
		for(int j=1; j<=m; ++j){
			int ch=getchar();
			if(ch=='.')
				a[i][j]=0;
			else
				if(ch=='*')
					a[i][j]=1;
				else{
					--j;
					continue;
				}
		}
	}
	for(int i=n; --i; )
		for(int j=m; --j>1; )
			if(a[i][j])
				a[i][j]=min(a[i+1][j-1],min(a[i+1][j],a[i+1][j+1]))+1;
	int ans=0;
	for(int i=n; i; --i)
		for(int j=m; j; --j)
			ans+=a[i][j];
	printf("%d\n",ans);
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}