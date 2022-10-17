#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 mrand(42);
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<",";cout<<endl;
#define prt(a, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int,int> pii;

const int maxn = 2005;
int a[maxn],b[maxn],c[maxn],d[maxn];
int mx[1000006];
int main() {
    int n,m;
    cin>>n>>m;
    ii cin>>a[i]>>b[i];
    ij cin>>c[i]>>d[i];
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            if(a[i] > c[j] || b[i] > d[j]) continue;
            int x = c[j] - a[i] + 1, y = d[j] - b[i] + 1;
            mx[x-1] = max(mx[x-1], y);
        }
    }
    int ans = 1e9;
    for(int i=1000000;i>=0;--i) mx[i] = max(mx[i], mx[i+1]);
    for(int i=1000000;i>=0;--i) ans = min(ans, mx[i] + i);
    cout << ans << endl;
}