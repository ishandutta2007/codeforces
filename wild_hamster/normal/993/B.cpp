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
#define ROW 5
#define COL 102
typedef int ll;
using namespace std;
ll n,i,j,k,z,m,q,h,r,timer,mx,l, cnt, u,v,t,s,tot;
vector<ll> f;

pii a[105], b[105];
set<ll> ans;
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i].X >> a[i].Y;
    for (int i = 0; i < m; i++)
        cin >> b[i].X >> b[i].Y;
    ll can = true;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
        map<ll, ll> tmp;
        tmp[a[i].X]++;
        tmp[a[i].Y]++;
        tmp[b[j].X]++;
        tmp[b[j].Y]++;
        if (tmp.size() == 3) {

            ll need = 0;
            for (auto itr = tmp.begin(); itr != tmp.end(); itr++)
                if ((*itr).Y == 2)
                    need = (*itr).X;
            for (int k = 0; k < m; k++) {
                map<ll, ll> tmp2;
                tmp2[a[i].X]++;
                tmp2[a[i].Y]++;
                tmp2[b[k].X]++;
                tmp2[b[k].Y]++;
                if (tmp2.size() == 3) {
                    ll need1 = 0;
                    for (auto itr = tmp2.begin(); itr != tmp2.end(); itr++)
                    if ((*itr).Y == 2)
                        need1 = (*itr).X;
                    if (need != need1) {
                        cout << -1 << endl;
                        return 0;
                    }
                }
            }

            for (int k = 0; k < n; k++) {
                map<ll, ll> tmp2;
                tmp2[a[k].X]++;
                tmp2[a[k].Y]++;
                tmp2[b[j].X]++;
                tmp2[b[j].Y]++;
                if (tmp2.size() == 3) {
                    ll need1 = 0;
                    for (auto itr = tmp2.begin(); itr != tmp2.end(); itr++)
                    if ((*itr).Y == 2)
                        need1 = (*itr).X;
                    if (need != need1) {
                        cout << -1 << endl;
                        return 0;
                    }
                }
            }
            ans.insert(need);
        }
    }
    if (ans.size() == 1)
        cout << (*(ans.begin())) << endl;
    else
        cout << 0 << endl;
    return 0;
}