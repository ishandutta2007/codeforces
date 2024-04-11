#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<ll,ll>
#define X first
#define Y second
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 998244353
#define MAXN 1000005
typedef int ll;
using namespace std;
ll i,j,k,q,timer,x,y,n,m, cnt, even, flag, x1,y1,x2,y2, boom,r,c,z;
int a[100500], used[100500];
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        string t;
        int mx = 0;
        for (int j = 'a'; j <= 'z'; j++)
            used[j] = 0;
        for (int j = i; j < n; j++) {
            used[s[j]]++;
            t.push_back(s[j]);
            mx = max(mx, used[s[j]]);
            if (mx*2 <= j-i+1) {
                cout << "Yes" << endl;
                cout << t << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}