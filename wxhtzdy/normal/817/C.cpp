#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    long long N, S; cin >> N >> S;
    long long bot = 1, top = N, ans = N + 1;
    auto Check = [&](long long X) {
		long long sum = 0;
		for (long long i = X; i; i /= 10) sum += i % 10;
        return X - sum >= S;
	};
	while (bot <= top) {
        long long mid = bot + top >> 1;
        if (Check(mid)) {
			ans = mid;
            top = mid - 1;
        } else {
			bot = mid + 1;
        }
	}
	cout << N - ans + 1 << '\n';
    return 0;
}