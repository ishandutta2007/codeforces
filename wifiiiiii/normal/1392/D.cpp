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
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int,int> pii;

int dp[200005][4];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--) {
        int n;string s;
        cin>>n>>s;
        string t=s;
        for(char &c:t) if(c=='L') c='1';else c='0';
        if(n<=2) {cout<<0<<endl;continue;}
        if(n==3) {
            if(s[0]==s[1] && s[1]==s[2]) cout<<1<<endl;
            else cout<<0<<endl;
            continue;
        }
        int ans=1e9;
        for(int p=0;p<4;++p) {
            int cnt=pc(p);
            s=t;
            for(int i=0;i<2;++i) if(p>>i&1) s[i]=s[i]^1;
            for(int i=0;i<=n;++i) for(int j=0;j<4;++j) dp[i][j]=1e9+7;
            dp[0][0]=0;dp[0][1]=1;
            for(int i=0;i<n-1;++i) {
                for(int j=0;j<4;++j) {
                    if(dp[i][j]>=1e9) continue;
                    for(int k=0;k<4;++k) {
                        if((j&1)^(k>>1&1)) continue;
                        int a1=s[i-1]^(j>>1&1),
                                a2=s[i]^(k>>1&1),
                                a3=s[i+1]^(k&1);
                        if(a1 == a2 && a2 == a3) continue;
                        dp[i+1][k]=min(dp[i+1][k],dp[i][j]+(k&1));
                    }
                }
            }
            // dp[n-1][00] dp[n-1][01] dp[n-1][10] dp[n-1][10];
            for(int i=0;i<4;++i) {
                int tmp=dp[n-1][i];
                int a1=(i>>1&1)^s[n-2],a2=(i&1)^s[n-1];
                int b1=s[0],b2=s[1];
                if(a1==a2 && a2==b1) ++tmp;
                else if(a2==b1 && b1==b2) ++tmp;
                ans=min(ans,tmp+cnt);
            }
        }
        cout<<ans<<endl;
    }
}