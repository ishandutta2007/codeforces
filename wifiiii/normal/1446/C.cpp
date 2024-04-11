#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 mrand(42);
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
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int, int> pii;

const int maxn = 200005;
int a[maxn];
int tr[maxn*30][2], sz[maxn*30], tot = 0;
void insert(int x) {
    int p = 0;
    for(int i=29;i>=0;--i) {
        if(!tr[p][x>>i&1]) tr[p][x>>i&1]=++tot;
        p=tr[p][x>>i&1];
        sz[p]++;
    }
}
int dfs(int p) {
    int ls = tr[p][0], rs = tr[p][1];
    if(!ls && !rs) return 0;
    if(ls && rs) {
        int l = sz[ls] - 1, r = sz[rs] - 1;
        return min(l + dfs(rs), r + dfs(ls));
    }
    if(ls) return dfs(ls);
    return dfs(rs);
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;++i) {
        int x;
        cin >> x;
        insert(x);
    }
    cout << dfs(0) << endl;
}