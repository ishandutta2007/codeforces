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
const double pi=acos(-1);
const int maxn=100005;;
//const ll Mod=1000000007;
const ll Mod=998244353;
using namespace std;

struct node
{
    int x, y;
}a[300],b[300];


int main()
{
    sync;
    int n,m,k;
    cin>>n>>m>>k;
    int d=0,u=0,l=0,r=0;
    int sd=0,su=0,sl=0,sr=0;
    for(int i=1;i<=k;i++)
    {
        cin>>a[i].x>>a[i].y;
    }
    for(int i=1;i<=k;i++)
    {
        cin>>b[i].x>>b[i].y;
        r=max(r,b[i].y-a[i].y);
        l=max(l,a[i].y-b[i].y);
        u=max(u,a[i].x-b[i].x);
        d=max(d,b[i].x-a[i].x);
    }
    
    cout<<2*(n-1)+(m-1)*(n+1)<<endl;
    for(int i=1;i<n;i++)
    {
        cout<<"D";
    }
    for(int i=1;i<m;i++)
    {
        cout<<"R";
    }
    for(int i=1;i<=n;i++)
    {
        if(i%2)
        {
            rep(i,2,m)
                cout<<"L";
        }
        else
            rep(i,2,m)
                cout<<"R";
        if(i!=n)
            cout<<"U";
    }
    cout<<endl;
    
//    for(int i=1;i<=k;i++)
//    {
//        if(b[i].y>=a[i].y)
//        sr=max(sr,b[i].y-min(a[i].y-l,1));
//        if(b[i].y<=a[i].y)
//        sl=max(sl,max(m,a[i].y+r)-b[i].y);
//        if(b[i].x<a[i].x)
//        su=max(su,max(n,a[i].x+d)-b[i].x);
//        if(b[i].x>a[i].x)
//        sd=max(sd,b[i].x-min(a[i].x-l,1));
//    }
////    cout<<r<<' '<<l<<' '<<u<<' '<<d<<endl;
////    cout<<sr<<' '<<sl<<' '<<su<<' '<<sd<<endl;
//    if(min(sr+l,sl+r)+min(su+d,sd+u)<=2*n*m)
//    {
//        cout<<min(sr+l,sl+r)+min(su+d,sd+u)<<endl;
//        if(sr<sl)
//        {
//            for(int i=1;i<=l;i++)
//            {
//                cout<<"L";
//            }
//            rep(i,1,sr)
//            cout<<"R";
//        }
//        else
//        {
//            for(int i=1;i<=r;i++)
//            {
//                cout<<"R";
//            }
//            rep(i,1,sl)
//            cout<<"L";
//        }
//        if(su<sd)
//        {
//            for(int i=1;i<=d;i++)
//            {
//                cout<<"D";
//            }
//            rep(i,1,su)
//            cout<<"U";
//        }
//        else
//        {
//            for(int i=1;i<=u;i++)
//            {
//                cout<<"U";
//            }
//            rep(i,1,sd)
//            cout<<"D";
//        }
//        cout<<endl;
//    }
//    else
//    {
//        sd=0,su=0,sl=0,sr=0;
//        for(int i=1;i<=k;i++)
//        {
//            if(b[i].y>a[i].y)
//            sr=max(sr,b[i].y-min(a[i].y-l,1));
//            if(b[i].y<a[i].y)
//            sl=max(sl,max(m,a[i].y+r)-b[i].y);
//            if(b[i].x<=a[i].x)
//            su=max(su,max(n,a[i].x+d)-b[i].x);
//            if(b[i].x>=a[i].x)
//            sd=max(sd,b[i].x-min(a[i].x-l,1));
//        }
//        if(min(sr+l,sl+r)+min(su+d,sd+u)<=2*n*m)
//        {
//            cout<<min(sr+l,sl+r)+min(su+d,sd+u)<<endl;
//            if(su<sd)
//            {
//                for(int i=1;i<=d;i++)
//                {
//                    cout<<"D";
//                }
//                rep(i,1,su)
//                cout<<"U";
//            }
//            else
//            {
//                for(int i=1;i<=u;i++)
//                {
//                    cout<<"U";
//                }
//                rep(i,1,sd)
//                cout<<"D";
//            }
//            if(sr<sl)
//            {
//                for(int i=1;i<=l;i++)
//                {
//                    cout<<"L";
//                }
//                rep(i,1,sr)
//                cout<<"R";
//            }
//            else
//            {
//                for(int i=1;i<=r;i++)
//                {
//                    cout<<"R";
//                }
//                rep(i,1,sl)
//                cout<<"L";
//            }
//            cout<<endl;
//        }
//        else
//            cout<<-1<<endl;
//    }
    return 0;
}