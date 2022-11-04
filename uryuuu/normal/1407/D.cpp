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
#include<bitset>
#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216")  //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define flush fflush(stdout)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=300010;
const ll Mod=1000000007;
//const ll Mod = 998244353;

ll a[maxn];
int st1[maxn],st2[maxn]; //1 
int dp[maxn];
 
int main()
{
    sync;
    int n;
    cin>>n;
    rep(i,1,n)
    cin>>a[i];
    int cnt1=0;
    int cnt2=0;
    dp[n]=0;
    st1[++cnt1]=n;
    st2[++cnt2]=n;
    for(int i=n-1;i>=1;i--)
    {
        dp[i]=dp[i+1]+1;
        while(cnt1!=0)
        {
            if(a[i]>a[st1[cnt1]])
            {
                dp[i]=min(dp[i],dp[st1[cnt1]]+1);
                cnt1--;
            }
            else
                break;
        }
        if(cnt1!=0)
            dp[i]=min(dp[i],dp[st1[cnt1]]+1);
        while(cnt1!=0)
        {
            if(a[i]>=a[st1[cnt1]])
                cnt1--;
            else
                break;
        }
     
        st1[++cnt1]=i;
        
        while(cnt2!=0)
        {
            if(a[i]<a[st2[cnt2]])
            {
                dp[i]=min(dp[i],dp[st2[cnt2]]+1);
                cnt2--;
            }
            else
                break;
        }
        if(cnt2!=0)
            dp[i]=min(dp[i],dp[st2[cnt2]]+1);
        while(cnt2!=0)
        {
            if(a[i]<=a[st2[cnt2]])
                cnt2--;
            else
                break;
        }
       
        st2[++cnt2]=i;
        
    }
    cout<<dp[1]<<endl;
    
    return 0;
}