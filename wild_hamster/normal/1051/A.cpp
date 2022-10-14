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
#define MOD 998244353
#define ROW 5
#define N 1000005
typedef int ll;
using namespace std;
ll n,i,j,k,z,m,q,r,timer,mx,l, v,tot,x,y,INF, sz,ans;
ll a[100500];
bool f(string x) {
    int f1 = 0, f2 = 0, f3 = 0;
    for (int i = 0; i < x.size(); i++) {
        if (x[i] >= 'a' && x[i] <= 'z')
            f1 = 1;
        else if (x[i] >= 'A' && x[i] <= 'Z')
            f2 = 1;
        else f3 = 1;
    }
    return ((f1+f2+f3) == 3);
}
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
            string s;
        cin >> s;
        if (f(s)) {
            cout << s << endl;
            continue;
        }
        int m = s.size();
        int flag = 0;
        for (int i = 0; i < m; i++) {
            char tmp = s[i];
            s[i] = 'a';
            if (f(s)) {
                cout << s << endl;
                flag = 1;
                break;
            }
            s[i] = 'A';
            if (f(s)) {
                cout << s << endl;
                flag = 1;
                break;
            }
            s[i] = '0';
            if (f(s)) {
                cout << s << endl;
                flag = 1;
                break;
            }
            s[i] = tmp;
        }
        if (flag)
            continue;
        if (s[0] >= 'a' && s[0] <= 'z') {
            s[0] = 'A';
            s[1] = '0';
        } else if (s[0] >= 'A' && s[0] <= 'Z') {
            s[0] = 'a';
            s[1] = '0';
        } else {
            s[0] = 'A';
            s[1] = 'a';
        }
        cout << s << endl;

    }
    return 0;
}