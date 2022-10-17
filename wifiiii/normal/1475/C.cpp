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

const int maxn = 2e5+5;
int x[maxn], y[maxn];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int a, b, m;
        cin >> a >> b >> m;
        map<pair<int,int>, int> mp;
        unordered_map<int, int> mp1, mp2;
        for(int i=1;i<=m;++i) cin>>x[i];
        for(int i=1;i<=m;++i) cin>>y[i];
        for(int i=1;i<=m;++i) {
            int u = x[i], v = y[i];
            mp1[u]++;
            mp2[v]++;
        }
        ll ans = 0;
        for(int i=1;i<=m;++i) {
            ans += m - mp1[x[i]] - mp2[y[i]] + 1;
        }
        cout << ans / 2 << endl;
    }
}