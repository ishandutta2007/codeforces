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
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        trans[a[i]] = 0;
        c[i] = -1;
    }
    i = -1;
    ll lastx = 0;
    for (auto itr = trans.begin(); itr != trans.end(); itr++) {
        if (itr == trans.begin()) {
            trans[(*itr).X] = i+1;
            i = i+1;
        } else if (lastx+1 != (*itr).X) {
            trans[(*itr).X] = i+2;
            i += 2;
        } else {
            trans[(*itr).X] = i+1;
            i++;
        }
        lastx = (*itr).X;
    }
    for (int i = 0; i < n; i++) {
        a[i] = trans[a[i]];
        g[a[i]].push_back(i);
    }
    cout << endl;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
                ll j = i;
                ll pos = upper_bound(g[a[j]+1].begin(), g[a[j]+1].end(), i) - g[a[j]+1].begin();
                if (g[a[j]+1].size() == pos) {
                    continue;
                } else {
                    c[pos] = j;
                    gr[j].push_back(g[a[j]+1][pos]);
                    gr[g[a[j]+1][pos]].push_back(j);
                }
    }
    for (int i = 0; i < n; i++) if (!used[i]){
        mx = 1005000;
        l = 0;
        dfs(i);
        sum = 0;
        f.clear();
        superdfs(l);
        if (sum > ans) {
            ans = sum;
            ansv = f;
        }
    }
    cout << ans << endl;
    for (int i = 0; i < ansv.size(); i++)
        cout << ansv[i]+1 << " ";
    cout << endl;
    return 0;
}