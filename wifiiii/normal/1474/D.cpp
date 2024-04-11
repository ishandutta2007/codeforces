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

ll a[200005];
ll b[200005], mn[200005];
ll c[200005];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i=1;i<=n;++i) cin>>a[i];
        for(int i=1;i<=n;++i) b[i]=a[i]-b[i-1];
        int ok=1;
        for(int i=1;i<n;++i) if(b[i]<0) ok=0;
        if(b[n]) ok=0;
        if(ok) {
            cout << "YES" << endl;
            continue;
        }
        if(b[n]&1) {
            cout << "NO" << endl;
            continue;
        }
        mn[n+1]=mn[n+2]=1e18;
        for(int i=n;i>=1;--i) mn[i]=min(mn[i+2],b[i]);
        int p=1; while(p<n && b[p]>=0) ++p;
        for(int i=1;i<n;++i) {
            if(i>p) break;
            if(i%2!=n%2 && b[n]/2 != a[i+1]-a[i]) continue;
            if(i%2==n%2 && b[n]/2 != a[i]-a[i+1]) continue;
            if(mn[i+2] + 2 * (a[i+1] - a[i]) < 0 || mn[i+1] + 2 * (- a[i+1] + a[i]) < 0) continue;
            if(b[i] + a[i+1] - a[i] < 0) continue;
            ok = 1;
            break;
        }
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}