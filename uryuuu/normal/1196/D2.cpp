#include<iostream>
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
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define tm(a,b,c) max(max(a,b),c)
#define inf 0x3f3f3f3f
const ll Mod=1e9+7;
#define maxn 100010
using namespace std;
int a[200010],dp[3][200010];
string k1="RGB",k2="GBR",k3="BRG";
int main()
{
    
    sync
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int len=s.length();
        for(int i=0;i<=n+1;i++)
              dp[0][i]=dp[1][i]=dp[2][i]=0;
            for(int j=0;j<len;j++)
            {
                dp[0][j+1]=dp[0][j];
                dp[1][j+1]=dp[1][j];
                dp[2][j+1]=dp[2][j];
                if(s[j]==k1[j%3])
                    dp[0][j+1]++;
                if(s[j]==k2[j%3])
                    dp[1][j+1]++;
                if(s[j]==k3[j%3])
                    dp[2][j+1]++;
            }
        int zx=0;
        for(int j=0;j<=len-k;j++)
        {
            for(int i=0;i<3;i++)
            {
                zx=max(dp[i][j+k]-dp[i][j],zx);
            }
        }
        //        for(int i=0;i<len;i++)
        //            cout<<a[i]<<' ';
        //        cout<<endl;
        //        cout<<len<<endl;
        cout<<k-zx<<endl;
    }
    return 0;
}