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

struct node
{
    int x1,y1,x2,y2;
}a[35];

int n,m;

char s[2005][2005],b[2005][2005];
int v[30];

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        mm(v);
        int cnt=0;
        for(int i=0;i<=30;i++)
        {
            a[i].x1=a[i].y1=99999;
            a[i].x2=a[i].y2=-999999;
        }
        cin>>n>>m;
        int id;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>s[i][j];
                b[i][j]='.';
                if(s[i][j]!='.')
                {
                    id=ch(s[i][j]);
                    cnt=max(id,cnt);
                    v[id]=1;
                    a[id].x1=min(a[id].x1,i);
                    a[id].y1=min(a[id].y1,j);
                    a[id].x2=max(a[id].x2,i);
                    a[id].y2=max(a[id].y2,j);
                }
            }
        }
        
        if(cnt==0)
        {
            cout<<"YES"<<endl;
            cout<<0<<endl;
            continue;
        }
        
        int f=0;
        
        for(int k=1;k<=cnt;k++)
        {
            if(v[k])
            {
//                cout<<k<<' '<<a[k].x1<<' '<<a[k].y1<<' '<<a[k].x2<<' '<<a[k].y2<<endl;
                for(int i=a[k].x1;i<=a[k].x2;i++)
                    for(int j=a[k].y1;j<=a[k].y2;j++)
                    {
                        b[i][j]=char('a'+k-1);
//                        cout<<b[i][j]<<endl;
                    }
                if(a[k].x1!=a[k].x2&&a[k].y1!=a[k].y2)
                {
                    f=1;
                    break;
                }
            }
        }
//        for(int i=1;i<=n;i++)
//        {
//            for(int j=1;j<=m;j++)
//            {
//                cout<<b[i][j];
//            }
//            cout<<endl<<endl;;
//        }
//        for(int i=1;i<=n;i++)
//               {
//                   for(int j=1;j<=m;j++)
//                   {
//                       cout<<s[i][j];
//                   }
//                   cout<<endl;
//               }
//
        int x=a[cnt].x1,y=a[cnt].y1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
                if(s[i][j]!=b[i][j])
                {
                    f=1;
                    break;
                }
        }
        if(f==1)
        {
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        cout<<cnt<<endl;
        for(int i=1;i<=cnt;i++)
        {
            if(v[i])
            {
                cout<<a[i].x1<<' '<<a[i].y1<<' '<<a[i].x2<<' '<<a[i].y2<<endl;
            }
            else
            {
                cout<<x<<' '<<y<<' '<<x<<' '<<y<<endl;
            }
        }
        
        
    }
    
    return 0;
}