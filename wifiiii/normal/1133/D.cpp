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

int a[200005],b[200005];
int gcd(int a,int b) {return b==0?a:gcd(b,a%b);}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i) cin>>b[i];
    map<pair<int,int>,int>mp;
    int c=0;
    for(int i=1;i<=n;++i) {
        if(a[i]==0) {
            if(b[i]==0)++c;
            continue;
        }
        int g=gcd(a[i],b[i]);
        a[i]/=g,b[i]/=g;
        if(a[i]<0) a[i]=-a[i],b[i]=-b[i];
        mp[{a[i],b[i]}]++;
    }
    int mx=0;for(auto p:mp)mx=max(mx,p.second);
    cout<<mx+c<<endl;
}