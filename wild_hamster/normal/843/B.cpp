#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define MOD 1000000007
#define y1 dskgj
#define y2 dskfj
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,w,m, used[100500], start;
pii a[100500];
vector<pii> f;
int main() {
    //freopen("input.txt", "r", stdin);
    srand(time(0));
    /*ll mx = 0;
    for (i = 0; i < 1000; i++)
    {
        f.insert(0);
        f.insert(50001);
        for (j = 0; j < 1000; j++)
        {
            f.insert((rand()*15+rand())%50000+1);
        }
        ll cur = 0;
        for (auto itr = f.begin(); itr != f.end(); itr++)
        {
            mx = max(mx, (*itr)-cur);
            cur = (*itr);
        }
    }*/
    cin >> n >> start >> x;
    cout << "? " << start << endl;
    fflush(stdout);
    ll val, nxt;
    cin >> val >> nxt;
    f.push_back(mp(val, nxt));
    if (val >= x)
    {
        cout << "! " << val << endl;
        fflush(stdout);
        return 0;
    }
    int NN = 999;
    for (j = 0; j < NN; j++)
    {
        ll cur = (rand()*15+rand())%n+1;
        cout << "? " << cur << endl;
        fflush(stdout);
        cin >> val >> nxt;
        f.push_back(mp(val, nxt));
    }
    sort(f.begin(), f.end());
    for (i = NN; i >= 0; i--)
    {
        if (f[i].X < x)
        {
            val = f[i].X, nxt = f[i].Y;
            break;
        }
    }
    if (nxt == -1)
    {
        cout << "! " << -1 << endl;
        fflush(stdout);
        return 0;
    }
    int curval = val;
    for (i = 0; i < 999; i++)
    {
        cout << "? " << nxt << endl;
        fflush(stdout);
        cin >> val >> nxt;
        if (val >= x)
        {
            cout << "! " << val << endl;
            fflush(stdout);
            return 0;
        }
        if (nxt == -1)
        {
            cout << "! " << -1 << endl;
            fflush(stdout);
            return 0;
        }
    }
    return 0;
}