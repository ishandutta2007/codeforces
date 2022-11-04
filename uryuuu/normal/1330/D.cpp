#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>

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
const double pi=acos(-1);
const int maxn=100010;
//const ll Mod=1000000007;
const ll Mod=998244353;
using namespace std;


ll c[maxn];
ll dp[100];

int main()
{
    sync;
    int t;
    cin>>t;
    ll d,m;
    ll sum,s;
    ll p;
    while(t--)
    {
        for(int i=0;i<80;i++)
            dp[i]=1ll;
        sum=0;
        cin>>d>>m;
        ll x;
        for(int i=1;i<40;i++)
        {
            x=(1ll<<i)-1ll;
            if(x>=d)
            {
                p=1ll*d-(1ll<<(i-1))+1ll;
                for(int j=1;j<i;j++)
                {
                    dp[j]=dp[j]*(p+1)%m;
                    sum=(sum+dp[j])%m;
                }
                dp[i]=dp[i]*p%m;
                sum=(sum+dp[i])%m;
//                for(int j=1;j<=i;j++)
//                    cout<<dp[j]<<' ';
//                cout<<endl;
                break;
            }
            x=(1ll)<<(i-1);
            for(int j=1;j<i;j++)
            {
                dp[j]=dp[j]*(x+1)%m;
//                sum=(sum+dp[j])%m;
            }
            dp[i]=dp[i]*x%m;
//            sum=(sum+dp[i])%m;
//            for(int j=1;j<=i;j++)
//                cout<<dp[j]<<' ';
//            cout<<endl;
        }
        cout<<sum<<endl;
    }
    
    return 0;
}