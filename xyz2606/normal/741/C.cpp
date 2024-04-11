#include<bits/stdc++.h>
using namespace std;
const int N(2111111);
int mp[N], ans[N], a[N], b[N];
bool vst[N];
int main() {
	int n;
	scanf("%d", &n);
	for(int i(1); i <= n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		mp[x] = y;
		mp[y] = x;
		a[i] = x;
		b[i] = y;
	}
	for(int i(1); i <= 2 * n; i++) {
		if(vst[i] == false) {
			ans[i] = 1;
			vst[i] = true;
			int prv(i);
			for(int x(mp[i]); x != i; ) {
				ans[x] = ans[prv] ^ 1;
				vst[x] = true;
				//printf("%d %d\n", x, mp[x]);
				if(prv == mp[x]) {
					prv = x;
					if(x % 2 == 0) {
						x--;
					}else {
						x++;
					}
				}else {
					prv = x;
					x = mp[x];
				}
			}
		}
	}
	for(int i(1); i <= n; i++) {
		printf("%d %d\n", ans[a[i]] + 1, ans[b[i]] + 1);
	}
}