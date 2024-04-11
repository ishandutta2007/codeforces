#include<bits/stdc++.h>
using namespace std;
const int N(222222);
int a[N], b[N];
bool vst[N];
int main() {
	int n;
	scanf("%d", &n);
	for(int i(1); i <= n; i++) {
		cin >> a[i];
	}
	int tot(0);
	for(int i(0); i < n; i++) {
		cin >> b[i];
		tot ^= b[i];
	}
	int cnt(0);
	int ans(tot ^ 1);
	for(int i(1); i <= n; i++) {
		if(!vst[i]) {
			int x(i);
			do {
				vst[x] = true;
				x = a[x];
			} while(x != i);
			cnt++;
		}
	}
	if(cnt > 1)
		ans += cnt;
	cout << ans << endl;
}