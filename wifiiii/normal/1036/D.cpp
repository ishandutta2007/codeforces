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

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n;
    vector<int> a(n);
    ll suma = 0, sumb = 0;
    int cnt = 0;
    vector<ll> vis;
    for(int i=0;i<n;++i) {
        cin >> a[i];
        suma += a[i];
        vis.push_back(suma);
    }
    sort(vis.begin(), vis.end());
    cin >> m;
    vector<int> b(m);
    for(int i=0;i<m;++i) {
        cin >> b[i];
        sumb += b[i];
        int pos = lower_bound(vis.begin(), vis.end(), sumb) - vis.begin();
        if(pos < vis.size() && vis[pos] == sumb) ++cnt;
    }
    if(suma != sumb) {
        cout << -1 << endl;
        return 0;
    }
    cout << cnt << endl;
}