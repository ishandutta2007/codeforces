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

inline int read()
{
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x*f;
}
int dp[100005],mx[100005];
int t[100005],l[100005],r[100005];
int main() {
    int n=read(),m=read();
    for(int i=1;i<=m;++i) t[i]=read(),l[i]=read(),r[i]=read();
    memset(dp, -0x3f, sizeof(dp));
    for(int i=1;i<=m;++i) {
        if(t[i] >= abs(l[i]-1) + abs(r[i]-1)) dp[i] = 1;
        for(int j=i-1;j>=max(1,i-1001);--j) {
            if(t[i] - t[j] >= abs(l[i] - l[j]) + abs(r[i] - r[j])) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        if(i-1001>=0) dp[i]=max(dp[i], mx[i-1001] + 1);
        mx[i] = max(mx[i-1], dp[i]);
    }
    cout<<mx[m]<<endl;
}