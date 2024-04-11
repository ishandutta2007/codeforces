#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	long long ans = 0, cnt1 = 0;
	while (n--) {
		int tmp;
		scanf("%d", &tmp);
		if (tmp == 1) {
			++cnt1;
		} else {
			ans += cnt1;
		}
	}
	cout << ans << endl;
	return 0;
}