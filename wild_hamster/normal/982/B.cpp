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
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l,sum, ans;
ll a[200500],  b[200500];
map<ll, ll> ko;
set<ll> frees, ones;
ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a%b);
}
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d",&a[i]);
        ko[a[i]] = i+1;
        frees.insert(a[i]);
    }
    string s;
    cin >> s;
    for (int i = 0; i < 2*n; i++) {
        if (s[i] == '0') {
            auto itr = frees.begin();
            printf("%d ", ko[*itr]);
            ones.insert(*itr);
            frees.erase(itr);
        } else {
            auto itr = ones.end();
            itr--;
            printf("%d ", ko[*itr]);
            ones.erase(itr);
        }
    }
    return 0;
}