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

const int maxn = 2005;
struct node {
    int l,r,mid;
    bool operator < (const node & n) const {
        if(mid != n.mid) return mid < n.mid;
        return l < n.l || (l == n.l && r < n.r);
    }
}c[maxn];
int a[maxn], b[maxn][maxn];
int pre[maxn][maxn], suf[maxn][maxn];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;++i) {
        int l,r,mid;
        cin>>l>>r;
        mid=(l+r)/2;
        c[i]={l,r,mid};
    }
    sort(c+1,c+1+m);
    for(int i=1;i<=n;++i) {
        int L=i,R=i+k-1;
        for(int j=1;j<=m;++j) {
            b[i][j] = max(0,min(R,c[j].r)-max(L,c[j].l)+1);
        }
    }
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            pre[i][j] = pre[i][j-1] + b[i][j];
        }
        for(int j=m;j>=1;--j) {
            suf[i][j] = suf[i][j+1] + b[i][j];
        }
    }
    for(int j=1;j<=m;++j) {
        for(int i=1;i<=n;++i) {
            pre[i][j] = max(pre[i-1][j], pre[i][j]);
        }
        for(int i=n;i>=1;--i) {
            suf[i][j] = max(suf[i][j], suf[i+1][j]);
        }
    }
    int ans = 0;
    for(int i=1;i<=m;++i) {
        for(int j=1;j<=n;++j) {
            ans = max(ans, pre[j][i] + suf[j+1][i+1]);
        }
    }
    cout << ans << endl;
}