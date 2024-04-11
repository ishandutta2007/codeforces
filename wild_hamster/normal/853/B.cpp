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
#define SQ 320
#define N 8388607
typedef long long ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,l,timer;
ll a[300500], b[300500];
vector<pii> arriv[1005000], depart[1005000];
multiset<ll> arr[100500], dep[100500];
ll min_arr[100500], min_dep[100500];
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> m >> k;
    for (i = 0; i < m; i++)
    {
        int x,y,z,w;
        scanf("%d %d %d %d",&x,&y,&z,&w);
        if (y == 0)
        {
            depart[x].push_back(mp(z,w));
        } else
            arriv[x].push_back(mp(y,w));
    }
    ll start = 1;
    for (i = start+k; i <= 1000000; i++)
        for (j = 0; j < depart[i].size(); j++)
            dep[depart[i][j].X].insert(depart[i][j].Y);
    ll inf = (ll)1e+12;
    ll ans = inf;
    ll cur = 0;
    for (int i = 1; i <= n; i++)
    {
        if(dep[i].empty())
            min_dep[i] = inf;
        else
            min_dep[i] = (*(dep[i].begin()));
        min_arr[i] = inf;
        cur += min_arr[i] + min_dep[i];
    }
    for (int start = 1; start+k <= 1000000; start++)
    {
        for (j = 0; j < arriv[start].size(); j++)
        {
            ll v = arriv[start][j].X;
            cur -= min_arr[v];
            min_arr[v] = min(min_arr[v], arriv[start][j].Y);
            cur += min_arr[v];
        }
        for (j = 0; j < depart[start+k].size(); j++)
        {
            ll v = depart[start+k][j].X;
            cur -= min_dep[v];
            dep[v].erase(dep[v].find(depart[start+k][j].Y));
            if (dep[v].empty())
                min_dep[v] = inf;
            else
                min_dep[v] = (*(dep[v].begin()));
            cur += min_dep[v];
        }
        ans = min(ans, cur);
    }
    if (ans == inf)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}