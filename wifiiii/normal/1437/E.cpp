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
typedef pair<int,int> pii;

int a[500005],b[500005];
int solve(int l, int r, int L, int R) {
    if(l > r) return 0;
    set<pair<int,int>> s;
    s.insert({L, 0});
    for(int i=l;i<=r;++i) {
        auto it = s.upper_bound({a[i], 2e9});
        if(it == s.begin()) continue;
        --it;
        int x = it->second - 1, pos = a[i];
        pair<int,int> tmp = {pos, x};
        while(!s.empty() && s.upper_bound(tmp) != s.end() && s.upper_bound(tmp)->second >= x) {
            s.erase(s.upper_bound(tmp));
        }
        s.insert({pos, x});
    }
    int ret = 1e9;
    for(auto p : s) {
        if(p.first <= R) {
            ret = min(ret, p.second + r - l + 1);
        }
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i) a[i]-=i;
    for(int i=1;i<=k;++i) cin>>b[i];
    sort(b+1,b+1+k);
    int ok = 1;
    for(int i=2;i<=k;++i) {
        if(a[b[i]] < a[b[i-1]]) {
            ok = 0;
            break;
        }
    }
    if(!ok) return cout<<-1<<endl, 0;
    int ans = 0;
    if(k) {
        for(int i=1;i<k;++i) {
            ans += solve(b[i]+1, b[i+1]-1, a[b[i]], a[b[i+1]]);
        }
        ans += solve(1, b[1]-1, -1e9, a[b[1]]);
        ans += solve(b[k]+1, n, a[b[k]], 1e9);
    } else {
        ans = solve(1, n, -1e9, 1e9);
    }
    cout << ans << endl;
}