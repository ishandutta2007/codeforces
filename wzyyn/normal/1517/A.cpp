#include<bits/stdc++.h>
using namespace std;

void solve(){
	long long n;
	scanf("%lld",&n);
	if (n%2050)
		puts("-1");
	else{
		n/=2050;
		int s=0;
		for (;n;s+=n%10,n/=10);
		printf("%d\n",s);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}