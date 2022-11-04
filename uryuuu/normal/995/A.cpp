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
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'A')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=500005;
const ll Mod=1000000007;
//const ll Mod=998244353;

int a[10][200];
struct node
{
    int id,x,y;
    node(int _id=0,int _x=0,int _y=0)
    {
        id=_id;
        x=_x;
        y=_y;
    }
}ans[maxn];

int main()
{
    sync;
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(a[2][i]&&a[2][i]==a[1][i])
        {
            ans[++cnt]=node(a[2][i],1,i);
            a[2][i]=0;
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        if(a[3][i]&&a[3][i]==a[4][i])
        {
            ans[++cnt]=node(a[3][i],4,i);
            a[3][i]=0;
        }
    }
    
    int f=0;
    int sx,sy;
    for(int i=1;i<=n;i++)
    {
        if(a[2][i]==0)
        {
            f=1;
            sx=2;
            sy=i;
            break;
        }
        if(a[3][i]==0)
        {
            f=1;
            sx=3;
            sy=i;
            break;
        }
    }
    if(f==0)
    {
        cout<<-1<<endl;
        return 0;
    }
    
    int nx,ny;
    int d=2*n;
//    cout<<sx<<' '<<sy<<endl;
    for(int t=1;t<=200005;t++)
    {
        for(int i=1;i<=d-1;i++)
        {
            if(sx==2&&sy==1)
            {
                nx=3;ny=1;
            }
            else if(sx==3&&sy==n)
            {
                nx=2;ny=n;
            }
            else
            {
                if(sx==2)
                {
                    nx=sx;
                    ny=sy-1;
                }
                else
                {
                    nx=sx;
                    ny=sy+1;
                }
            }
            swap(a[sx][sy],a[nx][ny]);
            if(a[sx][sy])
            {
                ans[++cnt]=node(a[sx][sy],sx,sy);
            }
            sx=nx;
            sy=ny;
        }
        
        
        for(int i=1;i<=n;i++)
        {
            if(a[2][i]&&a[2][i]==a[1][i])
            {
                ans[++cnt]=node(a[2][i],1,i);
                a[2][i]=0;
            }
        }
        
        for(int i=1;i<=n;i++)
        {
            if(a[3][i]&&a[3][i]==a[4][i])
            {
                ans[++cnt]=node(a[3][i],4,i);
                a[3][i]=0;
            }
        }
        
        f=0;
        for(int i=1;i<=n;i++)
        {
            if(a[2][i])
            {
                f=1;
                break;
            }
            if(a[3][i])
            {
                f=1;
                break;
            }
        }
//
//        for(int i=1;i<=4;i++)
//        {
//            for(int j=1;j<=n;j++)
//            {
//                cout<<a[i][j]<<' ';
//            }
//            cout<<endl;
//        }
//        cout<<endl;
        
        
        if(f==0)
        {
            break;
        }
    }
    
    cout<<cnt<<endl;
    for(int i=1;i<=cnt;i++)
    {
        cout<<ans[i].id<<' '<<ans[i].x<<' '<<ans[i].y<<endl;
    }
    
    return 0;
}