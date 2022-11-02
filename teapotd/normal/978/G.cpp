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

struct Exam {
    int begin, end, cnt;
};

void run() {
    int n, m; cin >> n >> m;

    vector<Exam> exams(m);
    Vi plan(n, 0);

    each(e, exams) {
        cin >> e.begin >> e.end >> e.cnt;
        e.begin--;
        e.end--;
        plan[e.end] = m+1;
    }

    Vi ord(m);
    iota(all(ord), 0);
    sort(all(ord), [&](int l, int r) { return exams[l].end < exams[r].end; });

    each(i, ord) {
        auto& e = exams[i];
        int cur = e.begin;

        rep(j, 0, e.cnt) {
            while (cur < e.end && plan[cur] != 0) {
                cur++;
            }

            if (cur == e.end) {
                cout << -1 << '\n';
                return;
            }

            plan[cur] = i+1;
        }
    }

    each(e, plan) cout << e << ' ';
    cout << '\n';
}