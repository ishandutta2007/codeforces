#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define MOD 1000000007
#define y1 dskgj
#define y2 dskfj
#define SQ 320
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l;
ll a[200500],b[250005], c[200500];
vector<ll> ans;
ll sum(ll x) {
    int k = 0;
    while (x) {
        k += x%10;
        x /= 10;
    }
    return k;
}
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (int i = 0; i <= min(n, 100); i++) {
        if (sum(n-i) == i)
            ans.push_back(n-i);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] <<  endl;
    return 0;
}