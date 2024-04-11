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
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int,int> pii;

const int inf = 2e9;
struct seg {
    int l, r;
    bool operator < (const seg & s) const {
        return r-l > s.r-s.l || (r-l == s.r-s.l && r<s.r);
    }
};

set<seg> ss;
set<int> s;
void insert(int x) {
    s.insert(x);
    auto it = s.find(x);
    int l = *--it;
    int r = *++(++it);
    ss.erase({l, r});
    ss.insert({l, x});
    ss.insert({x, r});
}
void erase(int x) {
    auto it = s.find(x);
    int l = *--it;
    int r = *++(++it);
    ss.erase({l, x});
    ss.erase({x, r});
    ss.insert({l, r});
    s.erase(x);
}
int query() {
    if(s.size() <= 4) return 0;
    auto it1 = s.rbegin(); ++it1;
    int r = *it1;
    auto it2 = s.begin(); ++it2;
    int l = *it2;
    auto it = ss.begin();
    while(it->l == 0 || it->r == inf) ++it;
    return r-l-(it->r-it->l);
}
int main() {
    int n,q;
    cin>>n>>q;
    s.insert(0);
    s.insert(inf);
    ss.insert({0,inf});
    int mx=0;
    for(int i=1;i<=n;++i) {
        int x;
        cin>>x;
        insert(x);
    }
    cout<<query()<<endl;
    while(q--) {
        int x,y;
        cin>>x>>y;
        if(x==1) insert(y);
        else erase(y);
        cout<<query()<<endl;
    }
}