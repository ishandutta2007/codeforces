#include <iostream>
#include <unordered_map>
#define int long long

using namespace std;

unordered_map <int, int> mem;
int a, b;

void calc(int pos, int cnt, int len) {
	int ans = b * cnt * len;
	int d = 0;
	if (mem.find(pos * 2) != mem.end()) d = mem[pos * 2];
	else d = a;
	if (mem.find(pos * 2 + 1) != mem.end()) d += mem[pos * 2 + 1];
	else d += a;
	if (len != 1) ans = min(ans, d);
	mem[pos] = ans;
}


signed main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k >> a >> b;
	int a[k];
	for (int i = 0; i < k; i++) cin >> a[i];
	int N = (1 << n);
	for (int i = 0; i < k; i++) a[i] += N - 1;
	unordered_map <int, int> cnt;
	for (int i = n; i >= 0; i--) {
		cnt.clear();
		for (int j = 0; j < k; j++) {
			cnt[a[j]]++;
			a[j] /= 2;
		}
		for (pair <int, int> elem : cnt) calc(elem.first, elem.second, 1ll << (n - i));
	}
	cout << mem[1] << endl;
	return 0;
}