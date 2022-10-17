#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
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

ll gcd(ll a,ll b) {return b==0?a:gcd(b,a%b);}
int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for(int i=0;i<n;++i) cin>>x[i]>>y[i];
    ll g=0;
    for(int i=1;i<n;++i) {
        g=gcd(g, 1ll*(x[0]-x[i])*(x[0]-x[i])+1ll*(y[0]-y[i])*(y[0]-y[i]));
    }
    vector<int> ans;
    for(int i=1;i<n;++i) {
        ll dis = 1ll*(x[0]-x[i])*(x[0]-x[i])+1ll*(y[0]-y[i])*(y[0]-y[i]);
        if(dis / g % 2) ans.push_back(i);
    }
    cout << ans.size() << endl;
    for(int i : ans) cout << i + 1 << " "; cout << endl;
}