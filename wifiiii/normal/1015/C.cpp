#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define al(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pc(x) __builtin_popcount(x)
#define pb push_back

int a[100005], b[100005];
int main() {
    int n, m;
    cin >> n >> m;
    ll s = 0, sum = 0;
    ii cin >> a[i] >> b[i], s += b[i], sum += a[i];
    if(s > m) {
        return cout << -1 << endl, 0;
    }
    vector<int> v;
    ii v.push_back(a[i] - b[i]);
    int ans = 0;
    sort(v.begin(), v.end(), greater<int>());
    for(int i : v) {
        if(sum <= m) break;
        sum -= i;
        ++ans;
    }
    assert(sum <= m);
    cout << ans << endl;
}