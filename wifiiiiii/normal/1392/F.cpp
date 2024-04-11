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
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int,int> pii;
const int maxn = 1e6+5;
#define int ll
int a[maxn];
inline int read()
{
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x*f;
}
int32_t main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n=read();
    ii a[i]=read();
    int sum=0;ii sum+=a[i];
    sort(al(a));
    int r=0;
    if(n%2==0) sum+=n/2;
    r=sum%n;
    int lo=0;
    if(r) lo=sum/n-n/2+1;
    else {
        if(n%2) lo=sum/n-(n+1)/2+1;
        else lo=sum/n-(n+1)/2;
    }
    vector<ll> ans;
    for(int i=0;i<n;++i) {
        if(r && i==n-1) break;
        ans.pb(lo+i);
        if(r && i==r-1) ans.pb(lo+i);
    }
    for(int i:ans) printf("%lld ",i);
}