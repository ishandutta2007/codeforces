#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 500
#define mod 998244353
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

void upd(string &s,string &t)
{
    if(s=="" || s>t) s=t;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cas; cin>>cas; while(cas--)
    {
        int n,k; cin>>n>>k;
        string dp[2][2];
        cin>>dp[0][0];
        
        rep(i,0,n-1)
        {
            dp[(i+1)&1][0]=dp[(i+1)&1][1]="";
            if(dp[i&1][0]!="")
            {
                auto &s=dp[i&1][0];
                if(i>0)
                {
                    swap(s[i],s[i-1]);
                    upd(dp[(i+1)&1][0],s);
                    swap(s[i],s[i-1]);
                }
                if(i<n-1)
                {
                    swap(s[i],s[i+1]);
                    upd(dp[(i+1)&1][1],s);
                    swap(s[i],s[i+1]);
                }
                if(s[i]=='a'+k-1) s[i]='a';
                if(s[i]>'a') s[i]--;
                upd(dp[(i+1)&1][0],s);
            }
            if(dp[i&1][1]!="")
            {
                auto &s=dp[i&1][1];
                if(i>1)
                {
                    swap(s[i-1],s[i-2]);
                    upd(dp[(i+1)&1][0],s);
                    swap(s[i-1],s[i-2]);
                }
                if(s[i-1]=='a'+k-1) s[i-1]='a';
                if(s[i-1]>'a') s[i-1]--;
                upd(dp[(i+1)&1][0],s);
            }
        }
        cout<<dp[n&1][0]<<endl;
    }
    return 0;
}