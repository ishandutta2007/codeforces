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
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l,sum, ans, cnt;
vector<ll> f;
ll a[100500], b[100500];
ll t[100500];
bool pal(string x) {
    ll n = x.size();
    for (int i = 0; i < n; i++)
        if (x[i] != x[n-i-1])
            return false;
    return true;
}

int main() {
    //freopen("input.txt","r",stdin);
    string s;
    cin >> s;
    int n = s.size();
    ll flag = 1;
    for (int i = 0; i+1< n; i++)
        if (s[i] != s[i+1])
            flag = 0;
    if (flag) {
        cout << 0 << endl;
        return 0;
    }
    if (!pal(s)) {
        cout << n << endl;
    } else {
        cout << n-1 << endl;
    }
    return 0;
}