
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

vector<pii> ans;
const int maxn = 100005;
void solve(int l, int r) {
    if(l == r) return;
    int m = (l + r) / 2;
    solve(l, m);
    solve(m+1, r);
    for(int i=l;i<=m;++i) ans.push_back({i,i+m-l+1});
}
int main() {
    int n;
    cin >> n;
    int k = 31 - __builtin_clz(n);
    solve(1, 1<<k);
    solve(n-(1<<k)+1, n);
    cout << ans.size() << endl;
    for(auto p:ans) cout<<p.first<<" "<<p.second<<endl;
}