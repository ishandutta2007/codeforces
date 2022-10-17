
#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 42(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdasd cout<<"okok"<<endl;
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back

int cnt[30][30];
int par[30];
int find(int x) {return x==par[x]?x:par[x]=find(par[x]);}
int main() {
    int T;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        memset(cnt,0,sizeof(cnt));
        int ok = 1;
        for(int i=0;i<n;++i) if(s[i] > t[i]) ok = 0;
        for(int i=0;i<26;++i) par[i]=i;
        if(!ok) {cout<<-1<<endl;continue;}
        for(int i=0;i<n;++i) {
            cnt[s[i]-'a'][t[i]-'a']++;
            par[find(s[i]-'a')]=find(t[i]-'a');
        }
        int ans=0;
        for(int i=0;i<26;++i) if(par[i]==i) ++ans;
        cout<<26-ans<<endl;
    }
}