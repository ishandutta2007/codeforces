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
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=100005;
const ll Mod=1000000007;

struct node
{
    ll x,y;
}s[maxn];
ll a[maxn];
 
int main()
{
    sync;
    ll x0,y0,ax,ay,bx,by,xs,ys,t;
    int cnt=0;
    cin>>x0>>y0>>ax>>ay>>bx>>by>>xs>>ys>>t;
    s[cnt].x=x0;
    s[cnt++].y=y0;
    while(1)
    {
        s[cnt].x=ax*s[cnt-1].x+bx;
        s[cnt].y=ay*s[cnt-1].y+by;
        if(s[cnt].x-xs>t||s[cnt].y-ys>t||(s[cnt].x-xs+s[cnt].y-ys)>t)
        {
            break;
        }
        cnt++;
    }
//    cout<<xs<<' '<<ys<<endl;
    for(int i=0;i<cnt;i++)
    {
//        cout<<s[i].x<<' '<<s[i].y<<endl;
        a[i]=(llabs(s[i].x-xs)+llabs(s[i].y-ys));
//        cout<<a[i]<<endl;
    }
    int da=0;
    ll w;
    for(int i=0;i<cnt;i++)
    {
        for(int j=i;j<cnt;j++)
        {
            w=(llabs(s[j].x-s[i].x)+llabs(s[j].y-s[i].y));
//            if(xs==10000000000000000)
//               cout<<labs(s[i].x-s[j].x)<<' '<<labs(s[i].y-s[j].y)<<' '<<' '<<s[i].x<<' '<<s[i].y<<' '<<s[j].x<<' '<<s[j].y<<' '<<w<<endl;
            if(w+min(a[i],a[j])<=t)
                da=max(da,j-i+1);
        }
    }
    cout<<da<<endl;
    return 0;
}