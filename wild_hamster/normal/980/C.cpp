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
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l,sum;
ll a[300500];
vector<pii> groups, tmp;
void merge1(ll x, ll y) {
    if (x == y)
        return;
    tmp.clear();
    for (int i = 0; i < x; i++)
        tmp.push_back(groups[i]);
    tmp.push_back(mp(groups[x].X, groups[y].Y));
    for (int i = y+1; i < groups.size(); i++)
        tmp.push_back(groups[i]);
    groups.clear();
    for (int i = 0; i < tmp.size(); i++)
        groups.push_back(tmp[i]);
}
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        scanf("%d",&a[i]);
    for (int i = 0; i < 256; i++)
        groups.push_back(mp(i, i+1));
    for (int i = 0; i < n; i++) {
        ll x = a[i];
        ll pos = upper_bound(groups.begin(), groups.end(), mp(x, MOD))-groups.begin();
        pos--;
        ll r = groups[pos].Y;
        j = pos;
        while (j > 0 && r - groups[j-1].X <= k)
            j--;
        merge1(j, pos);
        cout << groups[j].X << " ";
    }
    cout << endl;
    return 0;
}