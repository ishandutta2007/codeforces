#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
constexpr int max_n=2000;
int a[max_n+1];
void test(){
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",a+i);
	if(n<=2){
		printf("%d\n",abs(a[n]-a[1]));
		return;
	}
	int ans=a[n]-a[1];
	for(int i=1; i<n; ++i){
		const int t=a[i]-a[i+1];
		if(t>ans)
			ans=t;
	}
	int mx=a[n];
	for(int i=2; i<n; ++i)
		if(a[i]>mx)
			mx=a[i];
	mx-=a[1];
	if(mx>ans)
		ans=mx;
	int mn=a[1];
	for(int i=2; i<n; ++i)
		if(a[i]<mn)
			mn=a[i];
	mn=a[n]-mn;
	if(mn>ans)
		ans=mn;
	printf("%d\n",ans);
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}