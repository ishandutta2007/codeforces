#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2005;

int n , m ,  x , y , ans , C[N][N] , k;

void init(void) {
	for(int i = 1;i < N;++ i) {
		for(int j = 1;j < N;++ j) {
			if(i >= j) C[i][j] = i - j + 1;
		}
	}
}

char s[N][N];

main(void) {
	init();
	cin >> n >> m >> k;
	for(int i = 1;i <= n;++ i) {
		scanf("%s" , s[i] + 1);
	}
	long long ans = 0;
	for(int i = 1;i <= n;++ i) {
		int now = 0;
		for(int j = 1;j <= m;++ j) {
			if(s[i][j] == '*') {
				ans += C[now][k];
				now = 0;
			}
			else {
				++ now;
			}
		}
		if(now < k) continue;
		ans += C[now][k];
	}
	if(k == 1) {
		cout << ans << endl;
		return 0;
	}
	for(int i = 1;i <= m;++ i) {
		int now = 0;
		for(int j = 1;j <= n;++ j) {
			if(s[j][i] == '*') {
				ans += C[now][k];
				now = 0;
			}
			else {
				++ now;
			}
		}
		ans += C[now][k];
	}
	cout << ans;
}