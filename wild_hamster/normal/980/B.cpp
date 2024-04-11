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
    cin >> n >> k;
    if (k % 2 == 0) {

    cout << "YES" << endl;
        for (int i = 0; i < n; i++)
            cout << ".";
        cout << endl;

        cout << ".";
        for (int i = 0; i < k/2; i++)
            cout << "#";
        for (int i = 0; i < n-k/2-1; i++)
            cout << ".";
        cout << endl;

        cout << ".";
        for (int i = 0; i < k/2; i++)
            cout << "#";
        for (int i = 0; i < n-k/2-1; i++)
            cout << ".";
        cout << endl;

        for (int i = 0; i < n; i++)
            cout << ".";
        cout << endl;
        return 0;
    } else
    if (k <= n-2) {

    cout << "YES" << endl;
        for (int i = 0; i < n; i++)
            cout << ".";
        cout << endl;

        cout << ".";
        for (int i = 0; i < k/2; i++)
            cout << "#";
        for (int i = 0; i < (n-2)/2-k/2; i++)
            cout << ".";
        if (k%2)
            cout << "#";
        else
            cout << ".";
        for (int i = 0; i < (n-2)/2-k/2; i++)
            cout << ".";
        for (int i = 0; i < k/2; i++)
            cout << "#";
        cout << ".";
        cout << endl;

        for (int i = 0; i < n; i++)
            cout << ".";
        cout << endl;

        for (int i = 0; i < n; i++)
            cout << ".";
        cout << endl;
        return 0;
    } else if (k > n-2) {

    cout << "YES" << endl;
        for (int i = 0; i < n; i++)
            cout << ".";
        cout << endl;

        cout << ".";
        for (int i = 0; i < n-2; i++)
            cout << "#";
        cout << ".";
        cout << endl;

        cout << ".#";
        for (int i = 0; i < k-n; i++)
            cout << "#";
        for (int i = 0; i < n-(k-n+4); i++)
            cout << ".";
        cout << "#.";
        cout << endl;

        for (int i = 0; i < n; i++)
            cout << ".";
        cout << endl;
    }
    return 0;
}