#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        auto ask = [&](int a, int b, int c) -> int {
            cout << "? " << a << " " << b << " " << c << endl;
            int ret;
            cin >> ret;
            return ret;
        };
        auto solve = [&]() {
            vector<int> ans(n + 1, -1), qwq(n + 1, -1);
            int a1 = -1, a2 = -1, a3 = -1, a4 = -1, a5 = -1, a6 = -1;
            for(int i = 1; i <= n; i += 3) {
                qwq[i] = ask(i, i + 1, i + 2);
                if(qwq[i] == 0 && a1 == -1) {
                    a1 = i;
                    a2 = i + 1;
                    a3 = i + 2;
                } else if(qwq[i] == 1 && a4 == -1) {
                    a4 = i;
                    a5 = i + 1;
                    a6 = i + 2;
                }
            }
            assert(a1 != -1 && a4 != -1);
            int l = qwq[a1], r = qwq[a4];
            assert(l != r);
            // a1, a2  1  l a4, a5, a6  l
            for(int i : {a1, a2}) {
                int f = 7;
                if(ask(i, a4, a5) == l) {
                    f ^= 1 << 2;
                }
                if(ask(i, a4, a6) == l) {
                    f ^= 1 << 1;
                }
                if(ask(i, a5, a6) == l) {
                    f ^= 1 << 0;
                }
                int x = -1, y = -1;
                if(__builtin_popcount(f) == 1) {
                    // i = l, j = l
                    int j = -1;
                    if(f == 4) j = a6;
                    if(f == 2) j = a5;
                    if(f == 1) j = a4;
                    x = i; ans[i] = ans[j] = l;
                    for(int k : {a4, a5, a6}) {
                        if(k != j) {
                            ans[k] = r;
                            y = k;
                        }
                    }
                    for(int p : {a1, a2, a3}) {
                        if(ans[p] != -1) continue;
                        ans[p] = ask(x, y, p);
                    }
                    // x -> l, y -> r
                    for(int p = 1; p <= n; p += 3) {
                        if(ans[p] != -1) {
                            assert(ans[p + 1] != -1 && ans[p + 2] != -1);
                            continue;
                        }
                        ans[p] = ask(x, y, p);
                        ans[p + 1] = ask(x, y, p + 1);
                        ans[p + 2] = ask(x, y, p + 2);
                    }

                    int cnt = 0;
                    for(int p = 1; p <= n; ++p) {
                        if(ans[p] == 0) ++cnt;
                    }
                    cout << "! " << cnt << " ";
                    for(int p = 1; p <= n; ++p) {
                        if(ans[p] == 0) cout << p << " ";
                    }
                    cout << endl;

                    return;
                }
            }
            //  return a4, a5, a6 = r
            int x = -1, y = a4, f = 7;
            ans[a4] = ans[a5] = ans[a6] = r;
            if(ask(a1, a2, a4) == r) {
                f ^= 1 << 2;
            }
            if(ask(a2, a3, a4) == r) {
                f ^= 1 << 1;
            }
            if(ask(a1, a3, a4) == r) {
                f ^= 1 << 0;
            }
            ans[a1] = ans[a2] = ans[a3] = l;
            if(f == 7) {

            } else if(f == 1) {
                ans[a2] = r;
            } else if(f == 2) {
                ans[a1] = r;
            } else if(f == 4) {
                ans[a3] = r;
            } else {
                assert(0);
            }
            x = ans[a1] == l ? a1 : a2;

            for(int p = 1; p <= n; p += 3) {
                if(ans[p] != -1) {
                    assert(ans[p + 1] != -1 && ans[p + 2] != -1);
                    continue;
                }
                ans[p] = ask(x, y, p);
                ans[p + 1] = ask(x, y, p + 1);
                ans[p + 2] = ask(x, y, p + 2);
            }

            int cnt = 0;
            for(int p = 1; p <= n; ++p) {
                if(ans[p] == 0) ++cnt;
            }
            cout << "! " << cnt << " ";
            for(int p = 1; p <= n; ++p) {
                if(ans[p] == 0) cout << p << " ";
            }
            cout << endl;

        };
        solve();
    }
}