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

int mp[400005],a[400005];
vector<pair<int,int>> g[200005];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i) {
        int x;
        cin>>x;
        a[i]=x;
        mp[x%m]++;
    }
    int M=n/m;
    int j=0;
    ll ans=0;
    for(int i=0;i<m;++i) {
        if(mp[i]<=M) continue;
        j=max(j,i);
        while(mp[i]>M) {
            while(mp[j%m]>=M) ++j;
            int p=min(mp[i]-M,M-mp[j%m]);
            mp[i]-=p,mp[j%m]+=p;
            g[i].push_back({j-i,p});
            ans+=1ll*(j-i)*p;

        }
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;++i) {
        if(g[a[i]%m].size()) {
            int tmp = a[i]%m;
            auto &p = g[tmp].back();
            --p.second;
            a[i] += p.first;
            if(!p.second) g[tmp].pop_back();
        }
        cout<<a[i]<<" ";
    }
    cout<<endl;
}