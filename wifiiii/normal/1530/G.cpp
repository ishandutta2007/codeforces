#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        string s, t;
        cin >> s >> t;
        if(s == t) {
            cout << 0 << endl;
            continue;
        }
        auto get = [](string s) {
            vector<int> ret;
            int cnt = 0;
            for(int i = 0; i < s.size(); ++i) {
                if(s[i] == '0') {
                    ++cnt;
                } else {
                    ret.push_back(cnt);
                    cnt = 0;
                }
            }
            ret.push_back(cnt);
            return ret;
        };
        vector<int> a = get(s), b = get(t);
        if(a.size() != b.size() || k + 1 > a.size() || k == 0) {
            cout << -1 << '\n';
            continue;
        }
        auto calc = [&](vector<int> &a, vector<pair<int,int>> &sa, int l, int lres) {
            assert(l >= 0 && l + k < a.size());
            assert(lres >= 0 && lres <= a[l] + a[l+k]);
            int L = 0, R = 0, cur = 0, rres = a[l] + a[l+k] - lres;
            for(int i = 0; i <= l + k; ++i) {
                cur += a[i] + 1;
                if(i == l) {
                    L = cur;
                }
                if(i + 1 == l + k) {
                    R = cur;
                }
            }
            if(lres <= a[l]) {
                sa.emplace_back(L - (a[l] - lres), R);
            } else {
                assert(rres <= a[l+k]);
                sa.emplace_back(L, R + (a[l+k] - rres));
            }
            reverse(a.begin() + l + 1, a.begin() + l + k);
            a[l] = lres;
            a[l+k] = rres;
        };
        auto output = [&](vector<pair<int,int>> sa, vector<pair<int,int>> sb) {
            assert(sa.size() + sb.size() <= 4 * n);
            cout << sa.size() + sb.size() << endl;
            for(auto [l, r] : sa) {
                cout << l << " " << r << endl;
            }
            reverse(sb.begin(), sb.end());
            for(auto [l, r] : sb) {
                cout << l << " " << r << endl;
            }
        };
        vector<pair<int,int>> sa, sb;
        int c = a.size() - 1;
        if(c == k) {
            if(a[0] + a.back() == b[0] + b.back()) {
                if(equal(a.begin() + 1, a.end() - 1, b.begin() + 1, b.end() - 1)) {
                    calc(a, sa, 0, 0);
                    calc(b, sb, 0, 0);
                    output(sa, sb);
                    assert(a == b);
                } else {
                    if(equal(a.rbegin() + 1, a.rend() - 1, b.begin() + 1, b.end() - 1)) {
                        calc(a, sa, 0, 0);
                        calc(b, sb, 0, 0);
                        calc(b, sb, 0, 0);
                        output(sa, sb);
                        assert(a == b);
                    } else {
                        cout << -1 << endl;
                    }
                }
            } else {
                cout << -1 << endl;
            }
            continue;
        }
        assert(c > k);
        auto solve = [&](vector<int> &a, vector<pair<int,int>> &sa) {
            // push all non-zeros to last k + 1 position
            for(int i = 0; i < a.size() - k - 1; ++i) {
                calc(a, sa, i, 0);
            }
            if(k % 2 == 1) {
                // push all non-zeros to last position
                calc(a, sa, a.size() - k - 1, 0);
                for(int i = 0; i + 1 < k; ++i) {
                    calc(a, sa, a.size() - k - 1 - 1, 0);
                    calc(a, sa, a.size() - k - 1, 0);
                    // k - 1 times
                }
            } else {
                calc(a, sa, a.size() - k - 1, 0);
                for(int i = 0; i + 1 < k; ++i) {
                    calc(a, sa, a.size() - k - 1 - 1, a[a.size() - k - 1 - 1] + a[a.size() - 2]);
                    calc(a, sa, a.size() - k - 1, 0);
                    // k - 1 times
                }
            }
            // total : c + 1 - k - 1 + 1 + 2 * (k - 1) = c + k - 1 <= 2c < 2n
        };
        solve(a, sa);
        solve(b, sb);
        if(a == b) {
            output(sa, sb);
        } else {
            cout << -1 << endl;
        }
    }
}