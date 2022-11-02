#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#ifdef LOC
#include "debuglib.h"
#else
#define deb(...)
#define DBP(...)
#endif
using namespace std;
using   ll         = long long;
using   Vi         = vector<int>;
using   Pii        = pair<int, int>;
#define pb           push_back
#define mp           make_pair
#define x            first
#define y            second
#define rep(i, b, e) for (int i = (b); i < (e); i++)
#define each(a, x)   for (auto& a : (x))
#define all(x)       (x).begin(), (x).end()
#define sz(x)        int((x).size())

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }
void run();

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(18);
    run();
    return 0;
}

constexpr int MAX_TAIL = 18;
ll L, R, ans;
Vi tail, digL, digR;

ll greatest(int len) {
    len = max(len, sz(tail));
    ll ret = 0;
    for (int i = sz(tail)-1; i >= 0; i--) {
        ret = ret*10 + tail[i];
    }
    rep(i, 0, len-sz(tail)) ret *= 10;
    return ret;
}

ll smallest(int len) {
    len = max(len, sz(tail));
    ll ret = tail[0];
    rep(i, 0, len-sz(tail)) ret *= 10;
    rep(i, 1, sz(tail)) ret = ret*10 + tail[i];
    return ret;
}

bool check() {
    if (sz(digL) == sz(digR)) {
        if (sz(tail) > sz(digL)) {
            return 0;
        }

        {
            int cnt[10] = {0};
            each(c, tail) cnt[c]++;
            cnt[0] = sz(digL)-sz(tail);

            bool eq = 1, ok = 1;

            rep(i, 0, sz(digL)) {
                int dl = digL[i], dr = digR[i];
                if (eq) {
                    if (dl == dr) {
                        if (cnt[dl] == 0) {
                            ok = 0;
                            break;
                        }
                        cnt[dl]--;
                    } else {
                        rep(c, dl+1, dr) {
                            if (cnt[c] > 0) {
                                return 1;
                            }
                        }
                        if (cnt[dl] == 0) {
                            ok = 0;
                            break;
                        }
                        cnt[dl]--;
                        eq = 0;
                    }
                } else {
                    rep(c, dl+1, 10) {
                        if (cnt[c] > 0) {
                            return 1;
                        }
                    }
                    if (cnt[dl] == 0) {
                        ok = 0;
                        break;
                    }
                    cnt[dl]--;
                }
            }

            if (ok) {
                return 1;
            }
        }

        {
            int cnt[10] = {0};
            each(c, tail) cnt[c]++;
            cnt[0] = sz(digL)-sz(tail);

            bool eq = 1, ok = 1;

            rep(i, 0, sz(digL)) {
                int dl = digL[i], dr = digR[i];
                if (eq) {
                    if (dl == dr) {
                        if (cnt[dl] == 0) {
                            ok = 0;
                            break;
                        }
                        cnt[dl]--;
                    } else {
                        rep(c, dl+1, dr) {
                            if (cnt[c] > 0) {
                                return 1;
                            }
                        }
                        if (cnt[dr] == 0) {
                            ok = 0;
                            break;
                        }
                        cnt[dr]--;
                        eq = 0;
                    }
                } else {
                    rep(c, 0, dr) {
                        if (cnt[c] > 0) {
                            return 1;
                        }
                    }
                    if (cnt[dr] == 0) {
                        ok = 0;
                        break;
                    }
                    cnt[dr]--;
                }
            }

            if (ok) {
                return 1;
            }
        }
    } else {
        ll gr = greatest(sz(digL));
        if (gr >= L && gr <= R) {
            return 1;
        }

        ll sm = smallest(sz(digL)+1);
        if (sm >= L && sm <= R) {
            return 1;
        }
    }

    return 0;
}

void gen(int d) {
    if (d == 10) {
        if (!tail.empty()) {
            ans += check();
        }
        return;
    }

    gen(d+1);
    if (sz(tail) < MAX_TAIL) {
        tail.pb(d);
        gen(d);
        tail.pop_back();
    }
}

void run() {
    cin >> L >> R;
    for (ll k = L; k > 0; k /= 10) digL.pb(int(k%10));
    for (ll k = R; k > 0; k /= 10) digR.pb(int(k%10));
    reverse(all(digL));
    reverse(all(digR));
    assert(sz(digL) <= sz(digR));
    gen(1);
    cout << ans << '\n';
}