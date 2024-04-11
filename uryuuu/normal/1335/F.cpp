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
const int maxn=1000010;
//const ll Mod=1000000007;
const ll Mod=998244353;


string d[maxn],s[maxn];
int n,m;
int nxt[maxn][22][2],ans[maxn][2];
int jg[maxn],vis[maxn];

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int st=n*m;
        for(int i=0;i<=st;i++)
        {
            jg[i]=0;
            vis[i]=0;
        }
        for(int i=0;i<n;i++)
        {
            cin>>d[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
        }
        
        int x,y,xx,yy;
      
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                x=i;
                y=j;
                xx=x;
                yy=y;
                if(s[x][y]=='U')
                    xx--;
                else if(s[x][y]=='D')
                    xx++;
                else if(s[x][y]=='R')
                    yy++;
                else
                    yy--;
                nxt[i*m+j][0][0]=xx;
                nxt[i*m+j][0][1]=yy;
                ans[i*m+j][0]=i;
                ans[i*m+j][1]=j;
            }
        }

        
        for(int k=1;k<=21;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    x=nxt[i*m+j][k-1][0];
                    y=nxt[i*m+j][k-1][1];
                    nxt[i*m+j][k][0]=nxt[x*m+y][k-1][0];
                    nxt[i*m+j][k][1]=nxt[x*m+y][k-1][1];
                }
            }
        }
        int stt=st;
        for(int k=21;k>=0;k--)
        {
            if(stt>=(1<<k))
            {
                stt-=(1<<k);
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<m;j++)
                    {
                        x=ans[i*m+j][0];
                        y=ans[i*m+j][1];
                        ans[i*m+j][0]=nxt[x*m+y][k][0];
                        ans[i*m+j][1]=nxt[x*m+y][k][1];
                    }
                }
            }
//            cout<<stt<<endl;
        }
//        cout<<stt<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                x=ans[i*m+j][0];
                y=ans[i*m+j][1];
//                cout<<x<<' '<<y<<' ';
                vis[x*m+y]++;
                if(d[i][j]=='0')
                    jg[x*m+y]++;
            }
//            cout<<endl;
        }
        int s1=0,s2=0;

        for(int i=0;i<=st;i++)
        {
            if(vis[i])
                s1++;
            if(jg[i])
                s2++;
        }
        cout<<s1<<' '<<s2<<endl;
        
    }
    
    return 0;
    
}