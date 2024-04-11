#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,x,y,ans1,ans2;
signed main(){
	scanf("%lld%lld",&n,&m);
	while (m--){
		scanf("%lld%lld",&x,&y);
		ans1+=x*y;
		ans2+=y;
	}
	if (ans2>n){
		puts("-1");
		return 0;
	}
	if (ans2<n){
		puts("1");
		return 0;
	}
	if (ans1%n==n*(n+1)/2%n){
		puts("1");
		return 0;
	}
	puts("-1");
}