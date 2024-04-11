#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S secondond
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

signed main() {
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        vector<bool> used(n);
        map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        sort(all(a));
        int answer = 0;
        for (auto it : a) {
            if (cnt[it] > 0) {
                cnt[it]--;
                if (cnt.count(it * x) && cnt[it * x] > 0) {
                    cnt[it * x]--;
                } else {
                    answer++;
                }
            }
        }
        cout << answer << '\n';
    }

}