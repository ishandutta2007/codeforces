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
//#include<unordered_map>
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
#define ch(a) (int(a-'A')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=1010;
//const ll Mod=1000000007;
const ll Mod=998244353;

int ns[60];
int nt[60];
int dp[maxn][60][60];
string s,t,c;
int slen,tlen;


void getns()
{
    int j=0,k=-1;
    ns[0]=-1;
    while(j<slen)
    {
        if(k==-1||s[j]==s[k])
        {
            j++;
            k++;
            ns[j]=k;
        }
        else
            k=ns[k];
    }
}

void getnt()
{
    int j=0,k=-1;
    nt[0]=-1;
    while(j<tlen)
    {
        if(k==-1||t[j]==t[k])
        {
            j++;
            k++;
            nt[j]=k;
        }
        else
            k=nt[k];
    }
}

char x;

int main()
{
    sync
    cin>>c>>s>>t;
    int n=c.length();
    slen=s.length();
    tlen=t.length();
    getns();
    getnt();
    memset(dp,-inf,sizeof(dp));
    dp[0][0][0]=0;
    int ans=-inf;
    int jj,kk;
    for(int i=0;i<n;i++)
    {
        for(int h=0;h<=26;h++)
        {
            x=char('a'+h);
            if(c[i]!='*'&&c[i]!=x)
                continue;
            for(int j=0;j<slen;j++)
            {
                for(int k=0;k<tlen;k++)
                {
                    int sum=0;
                    if(dp[i][j][k]==-inf)
                        continue;
                    jj=j;
                    while(jj!=-1&&s[jj]!=x)
                    {
                        jj=ns[jj];
                    }
                    kk=k;
                    while(kk!=-1&&t[kk]!=x)
                    {
                        kk=nt[kk];
                    }
                    jj++;
                    kk++;
                    if(jj==slen)
                    {
                        jj=ns[jj];
                        sum++;
                    }
                    if(kk==tlen)
                    {
                        kk=nt[kk];
                        sum--;
                    }
                    dp[i+1][jj][kk]=max(dp[i+1][jj][kk],dp[i][j][k]+sum);
                }
            }
        }
    }
    for(int i=0;i<slen;i++)
    {
        for(int j=0;j<tlen;j++)
        {
            ans=max(ans,dp[n][i][j]);
//            cout<<n<<' '<<i<<' '<<j<<' '<<dp[n][i][j]<<endl;
        }
    }
    cout<<ans<<endl;
    return 0;
}