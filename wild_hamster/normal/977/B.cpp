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
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l;
pair<pii,ll> a[300500];
ll t[1005000];
string s;
map<string,ll> f;

int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    cin >> s;
    for (int i = 0; i+1 < s.size(); i++)
        f[s.substr(i, 2)]++;
    y = -1;
    string t;
    for (auto itr = f.begin(); itr != f.end(); itr++)
    if (y < (*itr).Y) {
        y = (*itr).Y;
        t = (*itr).X;
    }
    cout << t << endl;
    return 0;
}