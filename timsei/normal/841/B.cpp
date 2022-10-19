#include<bits/stdc++.h>
using namespace std;

const int N = 2000005;

#define int long long

int n , a[N] , S[N];
int sum;

main() {
	scanf("%lld",&n);
	for(int i = 1;i <= n;i ++) scanf("%lld",&a[i]);
	for(int i = 1;i <= n;i ++) S[i] = a[i] + S[i - 1];
	if(S[n] % 2 == 1) {
		puts("First");
		return 0;
	}
	bool flag = 0;
	for(int i = 1;i <= n;i ++) {
		if(a[i] % 2 != 0) {
			flag =  1;
			break;
		}
	}
	if(!flag) puts("Second");
	else puts("First");
}