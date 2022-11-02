#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, int> PLI;

const int MAXN = 1e5 + 10;
const int MM = 1e9 + 7;
 
const ll P1 = 998246177;
const ll P2 = 998246519;
const ll M1 = 1000001957;
const ll M2 = 1000002821;
 
ll pw1[MAXN]; //, ipw1[MAXN];
// ll pw2[MAXN], ipw2[MAXN];
ll iP1, iP2;
 
ll pw(ll p, ll q, ll MOD) {
    ll ret = 1;
    for (; q; q >>= 1) {
        if (q & 1) ret = ret * p % MOD;
        p = p * p % MOD;
    }
    return ret;
} 

int n, m;
char s[MAXN], t[MAXN];

struct query {
    int idx, k;
    ll hs;
};

bool operator < (const query &a, const query &b) {
    return a.hs < b.hs;
}

vector<query> Q[MAXN]; 
int ans[MAXN];

PLI f[MAXN];

void solve(int casi){
    scanf("%s", s + 1);
    n = strlen(s + 1);
    iP1 = pw(P1, M1 - 2, M1);
    iP2 = pw(P2, M2 - 2, M2);
    pw1[0] = 1; // ipw1[0] = pw2[0] = ipw2[0] = 1;
    for (int i = 1; i <= n; i++) {
        pw1[i] = (pw1[i - 1] * P1) % M1;
        // pw2[i] = (pw2[i - 1] * P2) % M2;
        // ipw1[i] = (ipw1[i - 1] * iP1) % M1;
        // ipw2[i] = (ipw2[i - 1] * iP2) % M2;
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d%s", &x, t);
        y = strlen(t);
        ll hs = 0;
        for (int j = 0; j < y; j++) {
            hs = (hs * P1 + t[j] - 'a' + 1) % M1;
        }
        Q[y].push_back((query){i, x, hs});
        ans[i] = -1;
    }
    for (int l = 1; l <= n; l++) {
        if (Q[l].size()) {
            int u = n - l + 1;
            ll hs = 0;
            for (int j = 1; j <= l; j++) {
                hs = (hs * P1 + s[j] - 'a' + 1) % M1;
            }
            f[1] = PLI(hs, 1);
            for (int i = 2; i <= u; i++) {
                hs = ((hs * P1 + s[i + l - 1] - 'a' + 1 - (s[i - 1] - 'a' + 1) * pw1[l]) % M1);
                if (hs < 0) hs += M1;
                f[i] = PLI(hs, i);
            }
            if (Q[l].size() >= 100) {
                sort(f + 1, f + u + 1);
                sort(Q[l].begin(), Q[l].end());
                int ptr = 1;
                for (auto &q : Q[l]) {
                    while (ptr <= u && f[ptr].first < q.hs) ptr++;
                    if (ptr > u) break;
                    if (f[ptr].first == q.hs) {
                        int ptr2 = ptr + q.k - 1;
                        int ret = MM;
                        while (ptr2 <= u && f[ptr2].first == q.hs) {
                            ret = min(ret, f[ptr2].second - f[ptr].second);
                            ptr++;
                            ptr2++;
                        }
                        if (ret != MM) ans[q.idx] = ret + l;
                    }
                }
            }
            else {
                map<ll, vector<int>> pos;
                for (auto &q : Q[l]) pos[q.hs].clear();
                for (int i = 1; i <= u; i++) {
                    auto maki = pos.find(f[i].first);
                    if (maki != pos.end()) {
                        maki->second.push_back(i);
                    }
                }
                for (auto &q : Q[l]) {
                    auto &maki = pos[q.hs];
                    int ret = MM; 
                    for (int ptr = 0; ptr + q.k - 1 < maki.size(); ptr++)
                        ret = min(ret, maki[ptr + q.k - 1] - maki[ptr]);
                    if (ret != MM) ans[q.idx] = ret + l;
                }
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        printf("%d\n", ans[i]);
    }
}

int main(){
    int T = 1;
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}