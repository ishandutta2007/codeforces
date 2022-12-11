#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_n 200000
int a[max_n+1],c[max_n+1];
//int dp[max_n+1][10],prv[max_n+1][10];
il void test(){
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%1d",a+i);
	for(int j=1; j<10; ++j){
		int flg=1;
		for(int i=1,lst1=0,lst2=j; i<=n; ++i)
			if(a[i]<j){
				if(a[i]>=lst1)
					lst1=a[i];
				else{
					flg=0;
					break;
				}
				c[i]=1;
			}
			else{
				if(a[i]>=lst2)
					lst2=a[i];
				else{
					if(a[i]==j){
						lst1=j,c[i]=1;
						continue;
					}
					flg=0;
					break;
				}
				c[i]=2;
			}
		if(flg){
			for(int i=1; i<=n; ++i)
				printf("%d",c[i]);
			puts("");
			return;
		}
	}
	puts("-");
	return;
//	memset(dp[0],1,sizeof(dp[0]));
//	for(int i=1; i<=n; ++i){
//		if(a[i]>=a[i-1]){
//			memcpy(dp[i],dp[i-1],sizeof(dp[i]));
//			for(int j=0; j<10; ++j)
//				prv[i][j]=0;
//		}
//		else
//			memset(dp[i],0,sizeof(dp[i]));
//		for(int j=0; j<10; ++j)
//			if(j>=a[i-1]&&dp[i-1][a[i]])
//				dp[i][j]=1,prv[i][j]=1;
//	}
//	if(dp[n][9]){
//		for(int i=n,j=9,flg=1; i; --i){
//			c[i]=flg;
//			if(prv[i][j])
//				flg^=1,j=a[i];
//		}
//		for(int i=1; i<=n; ++i)
//			printf("%d",c[i]+1);
//		puts("");
//	}
//	else
//		puts("-");
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}