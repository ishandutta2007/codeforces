#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_n 1000
int a[max_n+1][max_n+1],t[max_n+1][max_n+1];
int solve(ci n,ci k){
	if(n<=k){
		for(int i=1; i<n; ++i)
			for(int j=i; ++j<=n; )
				t[i][j]=1;
		return 1;
	}
	int m=(n-1)/k+1;
	int ans=solve(m,k)+1;
	for(int i=1; i<n; ++i)
		for(int j=i; ++j<=n; ){
			if((i-1)/k==(j-1)/k)
				a[i][j]=ans;
			else
				a[i][j]=t[(i-1)/k+1][(j-1)/k+1];
		}
	for(int i=1; i<n; ++i)
		for(int j=i; ++j<=n; )
			t[i][j]=a[i][j];
	return ans;
}
il void test(){
	int n,k;
	scanf("%d%d",&n,&k);
	int ans=solve(n,k);
	printf("%d\n",ans);
	for(int i=1; i<n; ++i)
		for(int j=i; ++j<=n; )
			printf("%d ",t[i][j]);
}
int main(){
	test();
//	int t;
//	for(scanf("%d",&t); t; test(),--t);
	return 0;
}