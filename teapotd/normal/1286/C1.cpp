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

using Info = array<int, 26>;

#ifdef LOC

string _hidden = "f";

int getN() {
    return sz(_hidden);
}

vector<string> doAsk(int b, int e) {
    vector<string> ret;
    rep(i, b, e) {
        rep(j, i+1, e+1) {
            ret.pb(_hidden.substr(i, j-i));
            sort(all(ret.back()));
        }
    }
    deb(b, e, ret);
    return ret;
}

void answer(const string& s) {
    deb(s, _hidden);
    exit(0);
}

#else

int getN() {
    int n; cin >> n;
    return n;
}

vector<string> doAsk(int b, int e) {
    cout << "? " << b+1 << ' ' << e << endl;
    vector<string> ret((e-b)*(e-b+1)/2);
    each(f, ret) cin >> f;
    return ret;
}

void answer(const string& s) {
    cout << "! " << s << endl;
    exit(0);
}

#endif

vector<Info> ask(int b, int e) {
    vector<Info> ret;
    each(s, doAsk(b, e)) {
        ret.emplace_back();
        each(c, s) ret.back()[c-'a']++;
    }
    return ret;
}

void run() {
    int n = getN();
    auto A = ask(0, n);

    if (n == 1) {
        string s;
        rep(i, 0, 26) if (A[0][i]) s.pb(char(i+'a'));
        answer(s);
        return;
    }

    auto B = ask(1, n);

    each(s, B) A.erase(find(all(A), s));
    assert(sz(A) == n);

    sort(all(A), [&](const Info& l, const Info& r) {
        return accumulate(all(l), 0) < accumulate(all(r), 0);
    });

    string ans;
    Info last = {};

    each(s, A) {
        rep(i, 0, 26) {
            if (s[i] == last[i]+1) {
                ans.pb(char(i+'a'));
                break;
            }
        }
        last = s;
    }
    answer(ans);
}