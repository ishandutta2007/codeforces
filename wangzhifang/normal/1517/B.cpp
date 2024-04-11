#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_n 100
#define max_m 100
int b[max_n+1][max_m+1],c[max_n+1][max_m+1];
pair<int,pair<int,int> > a[max_n*max_m+1];
int cur[max_n+1];
bool vis[max_n+1][max_m+1];
il void test(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j){
			scanf("%d",b[i]+j),vis[i][j]=0;
			a[(i-1)*m+j]=make_pair(b[i][j],make_pair(i,j));
		}
	sort(a+1,a+n*m+1);
	for(int i=1; i<=m; ++i)
		vis[a[i].second.first][a[i].second.second]=1;
	for(int i=1; i<=n; ++i)
		cur[i]=1;
	for(int i=1; i<=m; ++i){
		int t=a[i].second.first;
		c[t][i]=a[i].first;
//		printf("%d (%d %d)\n",a[i].first,a[i].second.first,a[i].second.second);
//		printf("&%d\n",t);
		for(int k=1; k<=n; ++k){
			if(k==t)
				continue;
			for(int&j=cur[k]; vis[k][j]; ++j);
//			printf("*(%d,%d) %d\n",k,cur[k],b[k][cur[k]]);
			vis[k][cur[k]]=1;
			c[k][i]=b[k][cur[k]];
		}
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			printf("%d ",c[i][j]);
		}
		puts("");
	}
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}