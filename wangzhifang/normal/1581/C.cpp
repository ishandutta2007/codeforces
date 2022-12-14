#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_n 400
#define max_m 400
int a[max_n+1][max_m+1],b[max_n+1][max_m+1],prv[max_m+1];
il void test(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j){
			scanf("%1d",a[i]+j);
			b[i][j]=b[i-1][j]+a[i][j];
		}
	int ans=2147483647;
	for(int i=1; i<=n; ++i)
		for(int j=i+4; j<=n; ++j){
			int sum=0;
			prv[0]=-2147483647;
			for(int k=1,tmp; k<=m; ++k){
				int p=b[j-1][k]-b[i][k],q=2-a[i][k]-a[j][k];
				int r=j-i-1-p;
//				if(k>=4)
//					printf("%d\n",sum-prv[k-3]+r);
				if(k>=4)
					(tmp=sum-prv[k-3]+r)<ans&&(ans=tmp);
				sum+=p+q;
				prv[k]=max(prv[k-1],sum-r);
			}
		}
	printf("%d\n",ans);
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}