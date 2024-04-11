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

void run() {
    int n;
    string s;
    cin >> n >> s;

    int cnt[3] = {};
    each(c, s) cnt[c-'0']++;

    each(c, s) {
        int k = cnt[c-'0'];
        if (k > n/3) {
            rep(i, 0, 3) {
                if (cnt[i] < n/3 && i < c-'0') {
                    cnt[c-'0']--;
                    c = char(i+'0');
                    cnt[i]++;
                    break;
                }
            }
        }
    }

    for (int j = n-1; j >= 0; j--) {
        auto& c = s[j];
        int k = cnt[c-'0'];
        if (k > n/3) {
            for (int i = 2; i >= 0; i--) {
                if (cnt[i] < n/3) {
                    cnt[c-'0']--;
                    c = char(i+'0');
                    cnt[i]++;
                    break;
                }
            }
        }
    }

    cout << s << endl;
}