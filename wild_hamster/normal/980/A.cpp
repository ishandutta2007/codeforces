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
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l,sum;
ll a[300500];
ll b[1005000], c[1005000], t[1005000], used[1005000], sused[1005000];
vector<ll> g[1000500], gr[1005000], ansv, f;
map<ll, ll> trans;
void dfs(ll v) {
    if (used[v])
        return;
    used[v] = 1;
    if (a[v] < mx) {
        mx = a[v];
        l = v;
    }
    for (int i = 0; i < gr[v].size(); i++) {
        ll to = gr[v][i];
        dfs(to);
    }
}

void superdfs(ll v) {
    f.push_back(v);
    sum++;
    for (int i = 0; i < gr[v].size(); i++) {
        ll to = gr[v][i];
        if (to > v) {
            superdfs(to);
            break;
        }
    }
}

int main() {
    //freopen("input.txt","r",stdin);
    string s;
    cin >> s;
    ll k = 0, l = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == 'o')
        k++;
        else
            l++;
    if (k == 0 || l%k == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}