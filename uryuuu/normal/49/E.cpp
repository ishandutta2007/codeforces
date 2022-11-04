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
#include <chrono>
#include <random>
typedef long long ll;
typedef unsigned long long ull;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-10
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
#define umap(a) (a).reserve(1024);(a).max_load_factor(0.25);
using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=105;
const ll Mod=1000000007;
//const ll Mod=998244353;

ll ok1[maxn][maxn][maxn],ok2[maxn][maxn][maxn];
string s;
int a[maxn],b[maxn];
vector<pii>g[maxn];
ll dp[maxn][maxn];

int main()
{
    sync;
    cin>>s;
    int len1=s.length();
    for(int i=1;i<=len1;i++)
    {
        a[i]=ch(s[i-1]);
    }
    cin>>s;
    int len2=s.length();
    for(int i=1;i<=len2;i++)
    {
        b[i]=ch(s[i-1]);
    }
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        s="";
        cin>>s;
        g[ch(s[0])].push_back(mkp(ch(s[3]),ch(s[4])));
    }
    for(int i=1;i<=len1;i++)
        ok1[i][i][a[i]]=1;
    for(int len=2;len<=len1;len++)
    {
        for(int L=1;L<=len1;L++)
        {
            int R=L+len-1;
            if(R>len1)
                break;
            for(int u=1;u<=26;u++)
            {
                for(int i=L;i<=R-1;i++)
                {
                    for(pii f:g[u])
                    {
                        if(ok1[L][i][f.first]&&ok1[i+1][R][f.second])
                            ok1[L][R][u]=1;
                    }
                }
            }
        }
    }
    
    for(int i=1;i<=len2;i++)
        ok2[i][i][b[i]]=1;
    for(int len=2;len<=len2;len++)
    {
        for(int L=1;L<=len2;L++)
        {
            int R=L+len-1;
            if(R>len2)
                break;
            for(int u=1;u<=26;u++)
            {
                for(int i=L;i<=R-1;i++)
                {
                    for(pii f:g[u])
                    {
                        if(ok2[L][i][f.first]&&ok2[i+1][R][f.second])
                            ok2[L][R][u]=1;
                    }
                }
            }
        }
    }
    
    memset(dp,inf,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=len1;i++)
    {
        for(int j=1;j<=len2;j++)
        {
            for(int ii=1;ii<=i;ii++)
            {
                for(int jj=1;jj<=j;jj++)
                {
                    for(int c=1;c<=26;c++)
                    {
                        if(ok1[ii][i][c]&&ok2[jj][j][c])
                        {
                            dp[i][j]=min(dp[i][j],dp[ii-1][jj-1]+1);
                        }
                    }
                }
            }
        }
    }
    if(dp[len1][len2]<inf)
        cout<<dp[len1][len2]<<endl;
    else
        cout<<-1<<endl;
    return 0;
}