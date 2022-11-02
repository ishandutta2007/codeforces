#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;


const int N = 10;
int n, ans;
long long a[N], l[N], fa[N], ch[N], cnt[N];

void go(const int d) {
	if (d == n) {
		int tmp = ch[n] == 1 ? 0 : 1;
		for (int i = 0; i < n; ++i) {
			if (fa[i] == n) {
				tmp += cnt[i];
				if (cnt[i] > 1) {
					++tmp;
				}
			} else {
				if (cnt[i] > 1) {
					++tmp;
				}
			}
		}
		ans = min(ans, tmp);
		return;
	} 
	for (int i = 0; i < n; ++i) {
		if (l[i] % a[d] == 0 && i != d) {
			l[i] /= a[d];
			fa[d] = i;
			go(d + 1);
			l[i] *= a[d];
		}
	}
	fa[d] = n;
	++ch[n];
	go(d + 1);
	--ch[n];
}

int main() {
	scanf("%d", &n);
	int res = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		l[i] = a[i];
		long long tmp = a[i];
		for (long long j = 2; j * j <= tmp; ++j) {
			while (tmp % j == 0) {
				tmp /= j;
				++cnt[i];
			}
		}
		if (tmp != 1) {
			tmp /= tmp;
			++cnt[i];
		}
		res += cnt[i];
	}
	ans = res + n + 1; 
	go(0);
	cout << ans << endl;
	return 0;
}