#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=500010;
//const ll Mod=1000000007;
const ll Mod=998244353;


string s,t;
ll dp[3030][3030];

int main()
{
    sync;
    cin>>s>>t;
    int n=s.length();
    int m=t.length();
    for(int i=0;i<n;i++)
    {
        if(i>=m||s[0]==t[i])
            dp[i][i]=2ll;
    }
    int r;
    for(int len=2;len<=n;len++)
    {
        for(int l=0;l<n;l++)
        {
            r=l+len-1;
            if(r>=n)
                break;
            if(l>=m||s[len-1]==t[l])
                dp[l][r]=(dp[l][r]+dp[l+1][r])%Mod;
            if(r>=m||s[len-1]==t[r])
                dp[l][r]=(dp[l][r]+dp[l][r-1])%Mod;
        }
    }
    ll ans=0;
    for(int i=m-1;i<n;i++)
    {
        (ans+=1ll*dp[0][i])%=Mod;
    }
    cout<<ans<<endl;
    return 0;
}