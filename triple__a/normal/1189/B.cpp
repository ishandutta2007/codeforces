#include<bits/stdc++.h>
using namespace std;

const int maxn=100007;
int n;
int a[maxn];
int ans[maxn];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	if (a[n]>=a[n-1]+a[n-2]){
		printf("NO");
		return 0;
	}
	ans[(n+1)/2]=a[n];
	for (int i=1;i<=n/2;++i){
		ans[(n+1)/2-i]=a[n-i*2];
		ans[(n+1)/2+i]=a[n-i*2+1];
	} 
	printf("YES\n");
	for (int i=1;i<=n;++i){
		printf("%d ",ans[i]);
	}
	return 0;
}