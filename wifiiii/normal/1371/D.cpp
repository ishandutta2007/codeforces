
#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back

int a[505][505],ans[505][505];
struct node {
    int x, y, v;
    bool operator < (const node & n) const {
        return v < n.v || (v == n.v && x < n.x);
    }
};
int r[505],c[505];
int main() {
    int t;
    cin>>t;
    while(t--) {
        memset(ans,0,sizeof(ans));
        memset(r,0,sizeof(r));
        memset(c,0,sizeof(c));
        int n,m;
        cin>>n>>m;
        vector<node> v;
        for(int i=1;i<=n;++i) a[1][i]=i;
        for(int i=2;i<=n;++i) {
            memcpy(a[i], a[i-1], sizeof(a[i]));
            rotate(a[i]+1, a[i]+n, a[i]+1+n);
        }
        for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) v.push_back({i,j,a[i][j]});
        sort(all(v));
        for(int i=0;i<m;++i) ans[v[i].x][v[i].y]=1;

        for(int i=1;i<=n;++i) {
            for(int j=1;j<=n;++j) {
                r[i] += ans[i][j];
                c[j] += ans[i][j];
            }
        }
        int mr=r[1],Mr=r[1],mc=c[1],Mc=c[1];
        for(int i=1;i<=n;++i) mr=min(mr,r[i]),Mr=max(Mr,r[i]),mc=min(mc,c[i]),Mc=max(Mc,c[i]);
        cout<<1ll*(mr-Mr)*(mr-Mr)+1ll*(mc-Mc)*(mc-Mc)<<endl;
        for(int i=1;i<=n;++i) {
            for (int j = 1; j <= n; ++j)
                cout << ans[i][j];
            cout << endl;
        }
    }
}