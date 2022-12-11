#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
constexpr int max_n=100000;
int a[max_n+1];
void test(){
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	n=unique(a+1,a+n+1)-a-1;
	if(a[1]>1||n==1){
		puts("YES");
		return;
	}
	if(a[1]==0){
		if(a[2]>1)
			puts("YES");
		else
			puts("NO");
		return;
	}
	if(a[2]==2){
		puts("NO");
		return;
	}
	while(1){
		int now=n;
		do
			--now;
		while(n-now==a[n]-a[now]);
		++now;
//		printf("%d(%d)\n",a[now],now);
		if(now==n)
			n=now-1;
		else{
			puts("NO");
			return;
		}
		if(n==1){
			puts("YES");
			return;
		}
	}
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}