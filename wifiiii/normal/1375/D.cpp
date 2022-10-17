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

int a[1005],vis[1005];
inline int get() {for(int i=0;;++i) if(!vis[i]) return i;}
int b[1005];
int main() {
    int t;
    cin>>t;
    while(t--) {
        memset(vis,0,sizeof(vis));
        int n;
        cin>>n;
        vi ans;
        for(int i=0;i<n;++i) cin>>a[i],vis[a[i]]++;
        int ok=1;
        for(int i=1;i<n;++i) if(a[i]<a[i-1]) ok=0;
        int p=get();
        while(!ok) {
            while(p<n) {
                ok=1;
                for(int i=1;i<n;++i) if(a[i]<a[i-1]) ok=0;
                if(ok) break;
                vis[a[p]]--;
                a[p]=p;
                ans.pb(p);
                vis[a[p]]++;
                p=get();
            }
            ok=1;
            for(int i=1;i<n;++i) if(a[i]<a[i-1]) ok=0;
            if(ok) break;
            for(int j=0;j<n;++j) {
                int x=0;
                for(int i=0;i<n;++i) if(a[i]==j) {x=i;break;}
                if(x==j) continue;
                ans.pb(x);
                vis[a[x]]--;
                a[x]=p;
                vis[a[x]]++;
                p=get();
                break;
            }
        }
        cout<<ans.size()<<endl;
        for(int i:ans) cout<<i+1<<" ";cout<<endl;
    }
}