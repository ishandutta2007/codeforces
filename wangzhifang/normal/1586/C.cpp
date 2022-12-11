#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_n 1000000
#define max_m 1000000
bool vis[max_m+1];
char*str[max_n+1];
int a[max_m+1];
il void test(){
	int n,m;
	scanf("%d%d",&n,&m);
	str[0]=new char[m+1];
	for(int i=1; i<=m; ++i)
		str[0][i]='.';
	memset(vis,0,sizeof(vis));
	for(int i=1; i<=n; ++i){
		str[i]=new char[m+1];
		scanf("\n%s",str[i]+1);
		str[i][0]='.';
		for(int j=1; j<=m; ++j)
			if(str[i][j-1]=='X'&&str[i-1][j]=='X')
				vis[j]=1;
	}
	int cnt=0;
	for(int i=1; i<=m; ++i)
		if(vis[i])
			a[++cnt]=i;
	a[cnt+1]=m+1;
	int q;
	scanf("%d",&q);
	for(int l,r; q; --q){
		scanf("%d%d",&l,&r);
		if(*upper_bound(a+1,a+cnt+1,l)<=r)
			puts("NO");
		else
			puts("YES");
	}
}
int main(){
	test();
//	int t;
//	for(scanf("%d",&t); t; test(),--t);
	return 0;
}