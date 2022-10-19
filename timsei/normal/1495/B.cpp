#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int L[N], R[N], who[N], n, m, P[N], MAX = 0;

void fuck(int x) {
	who[x] = x; L[x] = R[x] = 1;
	for(int i = x - 1; i >= 1; -- i) {
		if(P[i + 1] > P[i]) R[i] = x, ++ L[x];
		else break;
	}
	for(int i = x + 1; i <= n; ++ i) {
		if(P[i - 1] > P[i]) {
			if(i == 7) {
			}
			L[i] = x; ++ R[x];
		} else break;
	}
	MAX = max(MAX, L[x]);
	MAX = max(MAX, R[x]);
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; ++ i) scanf("%d", &P[i]);
	if(P[1] > P[2]) {
		fuck(1);
	}
	for(int i = 2; i < n; ++ i) {
		if(P[i] > P[i - 1] && P[i] > P[i + 1]) {
			fuck(i);
		}
	}
	if(P[n] > P[n - 1]) fuck(n);
	int tot = 0;
	for(int i = 1; i <= n; ++ i) if(who[i] == i) {
		if(L[i] == MAX) ++ tot;
		if(R[i] == MAX) ++ tot;
	}
		
	int ans = 0;
	if(tot != 2) {
		puts("0");
		return 0;
	}
	
	for(int i = 1; i <= n; ++ i) if(who[i] == i) {
		if(L[i] == MAX && R[i] == MAX){
			if(MAX & 1) ++ ans;
		}
	}
	cout << ans << endl;
}