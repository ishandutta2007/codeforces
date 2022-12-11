#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_n 500
int a[max_n+1][max_n+1];
il void test(){
	int n;
	scanf("%d",&n);
	for(int i=1,x; i<=n; ++i){
		scanf("%d",&x);
		a[i][i]=x;
	}
	for(int i=1; i<n; ++i){
		int lst=a[i][1]>i?a[i][1]:0;
		for(int j=1; j<=n-i; ++j)
			if(lst){
				a[i+j][j]=lst;
				lst=a[i+j][j+1]>i?a[i+j][j+1]:0;
			}
			else
				a[i+j][j]=a[i+j][j+1];
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=i; ++j)
			printf("%d ",a[i][j]);
		puts("");
	}
}
int main(){
	test();
//	int t;
//	for(scanf("%d",&t); t; test(),--t);
	return 0;
}