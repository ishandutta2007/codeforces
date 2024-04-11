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
#define COL 10
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l, cnt, u,v,t,s,tot;
vector<ll> f1,f2;
int main() {
    //freopen("input.txt","r",stdin);
    ll v1,v2,t,d;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'r')
            f1.push_back(i+1);
    }
    for (int i = s.size()-1; i >= 0; i--) {
        if (s[i] == 'l')
            f1.push_back(i+1);
    }
    for (int i = 0; i < f1.size(); i++)
        printf("%d\n",f1[i]);
    return 0;
}