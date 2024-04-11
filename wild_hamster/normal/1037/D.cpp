#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 1000000007
typedef long long ll;
using namespace std;
const int INF = 1000*1000*1000;
ll n,m,k,x,y;
ll a[1000500];
set<ll> g[500500];
vector<ll> f;
ll used[1005000];
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int x,y;
        scanf("%d %d", &x, &y);
        g[x].insert(y);
        g[y].insert(x);
    }
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        a[i] = x;
    }
    if (a[1] != 1) {
        cout << "No" << endl;
        return 0;
    }
    f.push_back(a[1]);
    int i = 0;
    while (i < f.size()) {
        int v = f[i++];
        int sz = f.size();
        if (sz == n) {
            cout << "Yes" << endl;
            return 0;
        }
        while (sz < n) {
            if (g[v].find(a[sz+1]) != g[v].end()) {
                f.push_back(a[sz+1]);
                g[v].erase(a[sz+1]);
                g[a[sz+1]].erase(v);
                sz++;
            } else {
                break;
            }
        }
        if (!g[v].empty()) {
            cout << "No" << endl;
            return 0;
        }
        if (sz == n) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
	return 0;
}