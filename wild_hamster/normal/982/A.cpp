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
#define PI 3.14159265359
typedef long long ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l,sum, ans;
ll a[200500],  b[200500];
ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a%b);
}
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i+1 < n; i++)
    if (s[i] == s[i+1] && s[i] == '1') {
        cout << "No" << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '1')
            continue;
        s[i] = '1';
        ll flag = 0;
        for (int j = 0; j+1 < n; j++) {
            if (s[j] == s[j+1] && s[j] == '1')
                flag = 1;
        }
        if (flag == 0) {
            cout << "No" << endl;
            return 0;
        }
        s[i] = '0';
    }
    cout << "Yes" << endl;
    return 0;
}