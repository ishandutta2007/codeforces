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

const int maxn = 100005;
int a[maxn];
ll s[maxn];
unordered_map<int,int> mp;
void build(int l,int r) {
    if(s[r]-s[l-1]<=1e9) mp[s[r]-s[l-1]]=1;
    if(a[l] == a[r]) return;
    int M=(a[l]+a[r])/2;
    int pos=upper_bound(a+l,a+r+1,M)-a-1;
    assert(pos>=l);
    assert(pos+1<=r);
    build(l,pos);
    build(pos+1,r);
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n,q;
        cin>>n>>q;
        for(int i=1;i<=n;++i) cin>>a[i];
        sort(a+1,a+1+n);
        for(int i=1;i<=n;++i) s[i]=s[i-1]+a[i];
        mp.clear();
        build(1,n);
        while(q--) {
            int x;
            cin>>x;
            if(mp.count(x)) cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
}