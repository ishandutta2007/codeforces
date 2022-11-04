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
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=510;  // 
const ll Mod=1000000007;
//const ll Mod = 998244353;


int s[maxn][maxn];
int dp[maxn];
int a[maxn];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i][i]=a[i];
    }
    for(int len=2;len<=n;len++)
    {
        for(int l=1;l<=n;l++)
        {
            int r=l+len-1;
            if(r>n)
                break;
            for(int k=l;k<r;k++)
            {
                if(s[l][k]==s[k+1][r]&&s[l][k]>0)
                    s[l][r]=s[l][k]+1;
            }
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        dp[i]=999999;
    }
    dp[0]=0;
    for(int r=1;r<=n;r++)
    {
        for(int l=1;l<=n;l++)
        {
            if(s[l][r])
            {
                dp[r]=min(dp[r],dp[l-1]+1);
            }
        }
    }
    cout<<dp[n]<<endl;
    
    return 0;
}