#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define MOD 1000000007
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
typedef long long ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l;
ll a[100500], b[100500];
ll x1,y1,x2,y2,r1,r2,x3,y3,r3;
string s;
set<ll> f[2];
vector<ll> ans[300500];
int main() {
    //freopen("input.txt","w",stdout);
    cin >> s;
    n = s.size();
    for (i = 0; i < n; i++)
    if (s[i] == '0') {
        f[0].insert(i+1);
    } else {
        f[1].insert(i+1);
    }
    int sz = 0;
    while (1) {
        if (f[0].empty() || f[1].empty()) {
            break;
        }
        int flag = -1;
        auto x = f[0].begin();
        set<ll>::iterator y;
        while (1) {
            if (flag != -1) {
                x = f[0].upper_bound(*y);
                f[1].erase(y);
            }
            else
                flag = 1;
            if (x == f[0].end()) {
                cout << -1 << endl;
                return 0;
            }
            ans[sz].push_back(*x);
            y = f[1].upper_bound(*x);
            f[0].erase(x);
            if (y == f[1].end()) {
                break;
            }
            ans[sz].push_back(*y);
        }
        sz++;
    }
    if (f[1].size() != 0) {
        cout << -1 << endl;
        return 0;
    }
    if (f[0].size() != 0) {
        for (auto itr = f[0].begin(); itr != f[0].end(); itr++) {
            ans[sz++].push_back(*itr);
        }
    }
    cout << sz << endl;
    for (int i = 0; i < sz; i++) {
            printf("%d", (int)ans[i].size());
        for (int j = 0; j < ans[i].size(); j++)
            printf(" %I64d", ans[i][j]);
        printf("\n");
    }
    return 0;
}