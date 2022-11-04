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
const int maxn=200010;  // 
const ll Mod=1000000007;
//const ll Mod = 998244353;

int a[200][200];
string s;
struct node
{
    int x,y,x2,y2,x3,y3;
}ans[10005];

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
        {
            cin>>s;
            for(int j=0;j<m;j++)
            {
                a[i][j+1]=int(s[j]-'0');
            }
        }
        int cnt=0;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i][j]==1)
                {
                    ans[++cnt].x=i;
                    ans[cnt].y=j;
                    if(j==m)
                    {
                        ans[cnt].x2=i+1;
                        ans[cnt].y2=j-1;
                        ans[cnt].x3=i+1;
                        ans[cnt].y3=j;
                    }
                    else if(a[i][j+1]==0)
                    {
                        ans[cnt].x2=i+1;
                        ans[cnt].y2=j+1;
                        ans[cnt].x3=i+1;
                        ans[cnt].y3=j;
                    }
                    else
                    {
                        ans[cnt].x2=i;
                        ans[cnt].y2=j+1;
                        if(a[i+1][j]==0)
                        {
                            ans[cnt].x3=i+1;
                            ans[cnt].y3=j+1;
                        }
                        else
                        {
                            ans[cnt].x3=i+1;
                            ans[cnt].y3=j;
                        }
                    }
                    a[ans[cnt].x][ans[cnt].y]^=1;
                    a[ans[cnt].x2][ans[cnt].y2]^=1;
                    a[ans[cnt].x3][ans[cnt].y3]^=1;
                }
            }
        }
        
        for(int i=1;i<m;i++)
        {
            if(a[n][i]==1)
            {
                ans[++cnt].x=n;
                ans[cnt].y=i;
                ans[cnt].x2=n-1;
                ans[cnt].y2=i;
                ans[cnt].x3=n-1;
                ans[cnt].y3=i+1;
                a[ans[cnt].x][ans[cnt].y]^=1;
                a[ans[cnt].x2][ans[cnt].y2]^=1;
                a[ans[cnt].x3][ans[cnt].y3]^=1;
                
                ans[++cnt].x=n;
                ans[cnt].y=i+1;
                ans[cnt].x2=n-1;
                ans[cnt].y2=i;
                ans[cnt].x3=n-1;
                ans[cnt].y3=i+1;
                a[ans[cnt].x][ans[cnt].y]^=1;
                a[ans[cnt].x2][ans[cnt].y2]^=1;
                a[ans[cnt].x3][ans[cnt].y3]^=1;
            }
        }
        if(a[n][m]==1)
        {
            ans[++cnt].x=n;
            ans[cnt].y=m;
            ans[cnt].x2=n-1;
            ans[cnt].y2=m;
            ans[cnt].x3=n-1;
            ans[cnt].y3=m-1;
            a[ans[cnt].x][ans[cnt].y]^=1;
            a[ans[cnt].x2][ans[cnt].y2]^=1;
            a[ans[cnt].x3][ans[cnt].y3]^=1;
            
            ans[++cnt].x=n;
            ans[cnt].y=m;
            ans[cnt].x2=n-1;
            ans[cnt].y2=m;
            ans[cnt].x3=n;
            ans[cnt].y3=m-1;
            a[ans[cnt].x][ans[cnt].y]^=1;
            a[ans[cnt].x2][ans[cnt].y2]^=1;
            a[ans[cnt].x3][ans[cnt].y3]^=1;
            
            ans[++cnt].x=n;
            ans[cnt].y=m;
            ans[cnt].x2=n-1;
            ans[cnt].y2=m-1;
            ans[cnt].x3=n;
            ans[cnt].y3=m-1;
            a[ans[cnt].x][ans[cnt].y]^=1;
            a[ans[cnt].x2][ans[cnt].y2]^=1;
            a[ans[cnt].x3][ans[cnt].y3]^=1;
        }
        cout<<cnt<<endl;
        for(int i=1;i<=cnt;i++)
        {
            cout<<ans[i].x<<' '<<ans[i].y<<' '<<ans[i].x2<<' '<<ans[i].y2<<' '<<ans[i].x3<<' '<<ans[i].y3<<endl;
        }
    }
    
    return 0;
}