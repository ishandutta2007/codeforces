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

struct intervals {
    int mn, mx;
    struct segs {
        int len, l, r;
        bool operator < (const segs & x) const {
            return len < x.len || (len == x.len && l > x.l);
        }
    };
    multiset<int> s;
    multiset<segs> ss;
    intervals(int mn = -1e9, int mx = 1e9):mn(mn),mx(mx) {
        s.insert(mn);
        s.insert(mx);
        ss.insert({mx - mn, mn, mx});
    }
    void insert(int x) {
        auto it = s.lower_bound(x);
        int r = *it;
        int l = *--it;
        ss.erase(ss.find({r - l, l, r}));
        ss.insert({x - l, l, x});
        ss.insert({r - x, x, r});
        s.insert(x);
    }
    void erase(int x) {
        auto it = s.find(x);
        int r = *++it; --it;
        int l = *--it;
        ss.erase(ss.find({x - l, l, x}));
        ss.erase(ss.find({r - x, x, r}));
        ss.insert({r - l, l, r});
        s.erase(s.find(x));
    }
    int go() {
        auto it=ss.rbegin();
        while(it->r == mx || it->l == mn) ++it;
        int l = it->l, r = it->r;
        int m = (l + r) / 2;
        insert(m);
        return m;
    }
    int size() {return s.size()-2;}
    int getmax() {
        if(size() < 2) return 0;
        auto it=ss.rbegin();
        while(it->r == mx || it->l == mn) ++it;
        return it->len;
    }
    int getmin() {
        if(size() < 1) return 0;
        return ss.begin()->len;
    }
};

int ans[200005];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        intervals s;
        s.insert(0);
        s.insert(n+1);
        for(int i=1;i<=n;++i) {
            ans[s.go()]=i;
        }
        for(int i=1;i<=n;++i) cout<<ans[i]<<" ";cout<<endl;
    }
}