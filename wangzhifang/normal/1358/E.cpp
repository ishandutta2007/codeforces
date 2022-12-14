#include <cstdio>
#include <algorithm>
using namespace std;
#define max_n 500000
int a[max_n+1];
long long sum[max_n+1];
int main(){
	int n,x;
	long long minn;
	scanf("%d",&n);
	sum[0]=0;
	for(int i=1; i<=(n+1)/2; ++i){
		scanf("%d",a+i);
		sum[i]=a[i]+sum[i-1];
	}
	scanf("%d",&x);
	for(int i=(n+3)/2; i<=n; ++i)
		sum[i]=x+sum[i-1];
	minn=sum[n];
	for(int i=n; i>n/2; --i){
		if(minn>0){
			printf("%d\n",i);
			return 0;
		}
		minn=min(minn-x,sum[n]-sum[n-i+1]);
	}
	puts("-1");
	return 0;
}