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
ll n,i,j,k,x,y,w,m, used[100500];
pii a[100500];
vector<ll> f;
vector<vector<ll> > g;
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (i = 0; i < n; i++)
    {
        scanf("%d",&a[i+1].X);
        a[i+1].Y = i+1;
    }
    sort(a+1, a+n+1);
    for (i = 1; i <= n; i++)
    if (!used[i])
    {
        int x = i;
        f.clear();
        while (!used[x])
        {
            f.push_back(x);
            used[x] = 1;
            x = a[x].Y;
        }
        g.push_back(f);
    }
    cout << g.size() << endl;
    for (i = 0; i < g.size(); i++)
    {
        cout << g[i].size();
        for (j = 0; j < g[i].size(); j++)
            printf(" %d", g[i][j]);
        printf("\n");
    }
    return 0;
}