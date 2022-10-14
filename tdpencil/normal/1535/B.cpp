#include <bits/stdc++.h>

int cnt[200001];
int main() {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    for(int test_case = 0; test_case < T; test_case++) {
        int n; cin >> n;
        vector<int> a(n);

        for(auto &i : a) cin >> i;
        for(auto &i : a) cnt[i]++;
        vector<int> b;
        vector<int> c;
        for(int i = int(1e5); i >= 1; i--) {
            
            if(i % 2 == 0) for(int j = 0; j < cnt[i]; j++) {
                b.push_back(i);
            }
            else {
                for(int j = 0; j < cnt[i]; j++) {
                    c.push_back(i);
                }
            }
        }
        for(auto &i : c) b.push_back(i);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(__gcd(b[i], 2 * b[j]) != 1) {
                    ++ans;
                }
            }
        }

        cout << ans << "\n";
        for(auto &i : a) cnt[i] = 0;
    }
}