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
#define COL 30000
typedef long long ll;
using namespace std;
ll n,i,j,k,z,m,q,h,r,timer,mx,l, cnt, u,v,t,s,tot,x,y,INF;
ll a[1200005], d[1205000];
pii b[1205000];
vector<ll> f;
ll gcd(ll a, ll b) {
    return (b==0?a:gcd(b,a%b));
}
int main() {

    //freopen("input.txt","r",stdin);
    cin >> n >> k;
    string s;
    cin >> s;
    for (char i = 'a'; i <= 'z'; i++)
        for (int j = 0; j < n; j++)
    if (s[j] == i) {
        f.push_back(j);
    }
    for (int i = 0; i < k; i++) {
        a[f[i]] = 1;
    }
    for (int i = 0; i < n; i++)
        if (!a[i])
            cout<<s[i];
    cout << endl;
    return 0;
}