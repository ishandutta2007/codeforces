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
#define mkp(a,b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=4010;
const ll Mod=1000000007;
//const ll Mod=998244353;
  

int a[maxn];
int dp[maxn][maxn];
int st[maxn],b[maxn];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        cin>>n;
        n*=2;
        int cnt=1;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
                dp[i][j]=0;
        }
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            b[i]=0;
        }
        st[1]=a[1];
        b[1]=1;
        for(int i=2;i<=n;i++)
        {
//            cout<<st[cnt]<<' '<<a[i]<<endl;
            if(st[cnt]>a[i])
            {
                b[cnt]++;
            }
            else
            {
                st[++cnt]=a[i];
                b[cnt]++;
            }
        }
//        for(int i=1;i<=cnt;i++)
//            cout<<b[i]<<' ';
//        cout<<endl;
        dp[0][0]=1;
        for(int i=1;i<=cnt;i++)
        {
            for(int j=n;j>=0;j--)
            {
                if(dp[i-1][j])
                {
                    dp[i][j+b[i]]=1;
                    dp[i][j]=1;
                }
            }
        }
//        for(int i=1;i<=cnt;i++)
//        {
//            for(int j=0;j<=n;j++)
//                if(dp[i][j])
//                    cout<<i<<' '<<j<<endl;
//        }
//        cout<<dp[cnt][2]<<' ';
        if(dp[cnt][n/2])
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        
    }
    
    return 0;
}