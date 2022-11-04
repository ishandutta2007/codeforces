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
#define ch(a) (int(a-'1')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=1005;
//const ll Mod=1000000007;
const ll Mod=998244353;
using namespace std;



char c[maxn][maxn];
int a[maxn][maxn],s[maxn][maxn];

int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            cin>>c[i][j];
    }
    for(int j=1;j<=m;j++)
        s[1][j]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(c[i][j]==c[i-1][j])
            {
                s[i][j]=s[i-1][j]+1;
            }
            else
            {
                s[i][j]=1;
            }
        }
    }
    ll sum=0;
    ll d;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int k=s[i][j];
            if(3*k>i)
                continue;
            if(s[i-k][j]==k&&s[i-2*k][j]>=k)
            {
                a[i][j]=1;
                int f=0;
                if(j==1)
                {
                    sum+=a[i][j];
                    continue;
                }
                for(int g=i-3*k+1;g<=i;g++)
                {
                    if(c[g][j]!=c[g][j-1])
                    {
                        f=1;
                        break;
                    }
                }
                if(f==0)
                {
                    a[i][j]+=a[i][j-1];
                }
                sum+=a[i][j];
//                cout<<i<<' '<<j<<endl;
            }
        }
    }
    
    cout<<sum<<endl;
    
    
    return 0;
}