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
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=200005;
const ll Mod=1000000007;


int a[20][2005];
int dp[1<<13],tp[1<<13],fp[1<<13];
struct node
{
    int da,id;
}b[2050];

bool cmp(node a,node b)
{
    return a.da>b.da;
}

int main()
{
    sync;
    int t;
    int n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>a[i][j];
        
        for(int i=1;i<=m;i++)
        {
            b[i].id=i;
            b[i].da=0;
            for(int j=1;j<=n;j++)
            {
                b[i].da=max(b[i].da,a[j][i]);
            }
        }
        
        sort(b+1,b+m+1,cmp);
        mm(dp);
        mm(fp);
        int id;
        for(int i=1;i<=min(n,m);i++)
        {
            id=b[i].id;
            memcpy(tp,dp,sizeof(tp));
            memcpy(fp,dp,sizeof(tp));
            for(int k=0;k<n;k++)
            {
                memcpy(fp,dp,sizeof(fp));
                for(int j=0;j<(1<<n);j++)
                {
                    for(int q=1;q<=n;q++)
                    {
                        int x=(q-1+k)%n;
                        if(j&(1<<x))
                        {
                            fp[j]=max(fp[j^(1<<x)]+a[q][id],fp[j]);
                        }
                    }
                }
                for(int j=0;j<(1<<n);j++)
                    tp[j]=max(tp[j],fp[j]);
            }
            for(int j=0;j<(1<<n);j++)
            {
                dp[j]=max(tp[j],dp[j]);
            }
        }
        cout<<dp[(1<<n)-1]<<endl;
    }
    return 0;
}