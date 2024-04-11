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

const int maxn = 300005;
int a[maxn], b[maxn];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        ii cin >> a[i];
        ij cin >> b[i];
        sort(a+1, a+1+n);
        reverse(a+1, a+1+n);
        int cur = 1;
        ll ans = 0;
        for(int i=1;i<=n;++i) {
            if(cur <= a[i]) {
                ans += b[cur];
                ++cur;
            } else {
                ans += b[a[i]];
            }
        }
        cout << ans << endl;
    }
}