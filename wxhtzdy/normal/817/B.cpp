#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    vector<int> A(N);
    for (int& i : A) cin >> i;
    sort(A.begin(), A.end());
    if (A[0] != A[1] && A[1] != A[2]) {
		int cnt = 0;
        for (int i : A) cnt += (i == A[2]);
        cout << cnt << '\n';
		return 0;
    }
	if (A[0] != A[1] && A[1] == A[2]) {
        int64_t cnt = 0, ans = 0;
        for (int i : A) {
            if (i == A[1]) {
                ans += cnt++;
            }
        }
        cout << ans << '\n';
        return 0;
	}
    if (A[0] == A[1] && A[1] != A[2]) {
		int cnt = 0;
        for (int i : A) cnt += (i == A[2]);
        cout << cnt << '\n';
		return 0;
    }
	if (A[0] == A[1] && A[1] == A[2]) {
		int64_t ans = 0, cnt[2] = {0, 0};
		for (int i : A) {
			if (i == A[0]) {
				ans += cnt[1];
                cnt[1] += cnt[0]++;
            }
		}
		cout << ans << '\n';
        return 0;
	}
	assert(false);
    return 0;
}