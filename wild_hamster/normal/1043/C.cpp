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
#define INF 998244353
#define MAXN 1000005
typedef long long ll;
using namespace std;
ll i,j,k,q,x,y,n,m,  x1,y1,x2,y2,z;
ll a[200500], b[200500];
string s;
vector<ll> f;
int main() {
    //freopen("input.txt", "r", stdin);
    //srand(time(0));
    string s;
    int ii = 1;
    while (ii--) {
    //cin >> s;
    string s;
    cin >> s;
    /*for (int i = 0; i < 15; i++) {
        s.push_back(rand()%2+'a');
    }*/
    int n = s.size();
    s.push_back('b');
    for (int i = 0; i < n; i++) {
        if (s[i] != s[i+1]) {
            cout << 1 << " ";
            reverse(s.begin(), s.begin()+i+1);
        } else {
            cout << 0 << " ";
        }
    }
    //cout << s << endl;
    }
    return 0;
}