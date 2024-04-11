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
const int maxn=200010;
const ll Mod=1000000007;
//const ll Mod = 998244353;


int dp[255][255][255];
int nxt[maxn][30];
string ss;
int s[maxn];
int L[5];
int d[5][400];

int main()
{
    sync;
    dp[0][0][0]=0;
    int n,q;
    cin>>n>>q;
    cin>>ss;
    for(int i=1;i<=n;i++)
        s[i]=ch(ss[i-1]);
    for(int i=1;i<=26;i++)
    {
        nxt[n+1][i]=n+1;
        nxt[n+2][i]=n+1;
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=26;j++)
            nxt[i][j]=nxt[i+1][j];
        nxt[i][s[i]]=i;
    }
    
    char c,xx;
    int id,x;
    while(q--)
    {
        cin>>c>>id;
        if(c=='-')
        {
            L[id]--;
        }
        else
        {
            cin>>xx;
            x=ch(xx);
            L[id]++;
            d[id][L[id]]=x;
            for(int i=0;i<=L[1];i++)
            {
                if(id==1)
                    i=L[1];
                for(int j=0;j<=L[2];j++)
                {
                    if(id==2)
                        j=L[2];
                    for(int k=0;k<=L[3];k++)
                    {
                        if(id==3)
                            k=L[3];
                        dp[i][j][k]=n+1;
                        if(i)
                            dp[i][j][k]=min(dp[i][j][k],nxt[dp[i-1][j][k]+1][d[1][i]]);
                        if(j)
                            dp[i][j][k]=min(dp[i][j][k],nxt[dp[i][j-1][k]+1][d[2][j]]);
                        if(k)
                            dp[i][j][k]=min(dp[i][j][k],nxt[dp[i][j][k-1]+1][d[3][k]]);
                    }
                }
            }
        }
        if(dp[L[1]][L[2]][L[3]]<=n)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
//        cout<<dp[L[1]][L[2]][L[3]]<<endl;
//        for(int i=1;i<=3;i++)
//        {
//            for(int j=1;j<=L[i];j++)
//                cout<<d[i][j]<<' ';
//            cout<<endl;
//        }
//        cout<<endl;
    }
    
    return 0;
}