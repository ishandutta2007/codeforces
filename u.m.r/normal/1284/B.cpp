#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;


ll pw(ll p, ll q){
    ll ret = 1;
    for (; q; q >>= 1){
        if (q & 1)
            ret = ret * p % MM;
        p = p * p % MM;
    }
    return ret;
}

int n;
std::vector<int> a;
vector<PII> b;
int c[MAXN];

void solve(int casi){
    //printf("Case #%d:", casi);
    scanf("%d", &n);
    int ye = 0;
    for (int i = 1; i <= n; i++) {
        int m;
        scanf("%d", &m);
        a.resize(m);
        for (int j = 0; j < m; j++) scanf("%d", &a[j]);
        int mx = MM;
        int p = MM, q = -1;
        int flag = 0;
        for (int j = 0; j < m; j++) {
            p = min(p, a[j]);
            q = max(q, a[j]);
            if (a[j] < mx) {
                mx = a[j];
            }
            else if (a[j] > mx) {
                flag = 1;
            }
        }
        ye += flag;
        if (!flag) {
            b.emplace_back(p, q);
        }
    }
    assert(ye + b.size() == n);
    ll ans = 1ll * n * n - 1ll * b.size() * b.size();
    // cout << ans << endl;
    // for (auto &o : b) {
    //     cout << o.first << ' ' << o.second << endl;
    // }
    for (auto &o : b) {
        c[o.first + 1]++;
    }
    for (int i = 1; i < MAXN; i++) {
        c[i] += c[i - 1];
    }
    for (auto &o : b) {
        ans += c[o.second];
    }
    cout << ans << endl;
}

int main(){
    int T = 1;
    //scanf("%d", &T);
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}