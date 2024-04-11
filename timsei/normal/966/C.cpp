#include <bits/stdc++.h>
using namespace std;

const int N = 1111111;

#define int long long

int n , a[N] , b[N] , tot;

queue <int> q[66];

main(void) {
	scanf("%lld" , &n);
	for(int i = 1;i <= n;++ i) {
		scanf("%lld", &a[i]);
		for(int j = 63;j >= 0;-- j) {
			if((1LL << j) & a[i]) {
				q[j].push(a[i]);
				break;
			}
		}
	}
	int now = 0;
	for(int i = 1;i <= n;++ i) {
		bool ok = 0;
		for(int j = 0;j < 64;++ j) {
			if((!(now & (1LL << j))) && !q[j].empty()) {
				now = now ^ q[j].front();
				a[++ tot] = q[j].front();
				q[j].pop();
				ok = 1;
				break;
			}
		}
		if(!ok) {
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	for(int i = 1;i <= n;++ i) printf("%lld " , a[i]);
}