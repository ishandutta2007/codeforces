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
typedef int ll;
using namespace std;
ll n,i,j,k,z,m,q,h,r,timer,mx,l, cnt, u,v,t,s,tot,x,y;
ll a[200005];
map<string, int> f;
string g(string x) {
    string ans;
    for (int i = 0; i < 20-x.size(); i++) {
        ans.push_back('0');
    }
    for (int i = 0; i < x.size(); i++) {
        ans.push_back((x[i]-'0')%2+'0');
    }
    return ans;
}
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        char c;
        string s;
        cin >> c >> s;
        if (c == '+')
            f[g(s)]++;
        else
        if (c == '-')
            f[g(s)]--;
        else
            cout << f[g(s)] << endl;
    }
    return 0;
}