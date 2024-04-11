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
ll n,m,k,y, x,sz, t;
string s;
ll a[555555], b[555555];
set<ll> g;
ll Abs(ll x) {
    return x>0?x:-x;
}
void brute(vector<ll> f) {
    /*for (int j = 0; j < f.size(); j++)
        cout << f[j] << " ";
    cout << endl;*/
    if (f.size() == 1) {
        g.insert(f[0]);
        return;
    }
    for (int i = 0; i+1 < f.size(); i++) {
        ll x = f[i];
        ll y = f[i+1];
        {
        vector<ll> f1;
        for (int j = 0; j < i; j++)
            f1.push_back(f[j]);
        f1.push_back(x-y);
        for (int j = i+2; j < f.size(); j++)
            f1.push_back(f[j]);
        brute(f1);
        }
        {
        vector<ll> f1;
        for (int j = 0; j < i; j++)
            f1.push_back(f[j]);
        f1.push_back(y-x);
        for (int j = i+2; j < f.size(); j++)
            f1.push_back(f[j]);
        brute(f1);
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //cin >> s;
    //cout << s.find("hyu") << endl;
    /*vector<ll> f;
    for (int i = 0; i < 7; i++)
        f.push_back(1<<i);
    brute(f);
    cout << g.size() << endl;*/
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        a[i] = x;
    }
    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    }
    x = 0, y = 0;
    ll ans = 0;
    ll min1 = (ll)1e+18;
    for (int i = 0; i < n; i++) {
        min1 = min(min1, Abs(a[i]));
        ans += Abs(a[i]);
        if (a[i] >= 0)
            x++;
        if (a[i] <= 0)
            y++;
    }
    if (min(x, y) == 0) {
        cout << ans-min1*2 << endl;
    } else {
        cout << ans << endl;
    }
	return 0;
}