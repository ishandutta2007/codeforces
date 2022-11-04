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
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define mkp make_pair
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=100010;
const ll Mod=1000000007;
//const ll Mod=998244353;


struct node
{
    double x,y;
}s[maxn];
int n;

bool check(double r)
{
    double l=-1e16;
    double rrr=1e16;
    for(int i=1;i<=n;i++)
    {
        double ss=2.0*r*s[i].y-1.0*s[i].y*s[i].y;
        if(ss<0)
            return 0;
        ss=sqrt(ss);
        l=max(s[i].x-ss,l);
        rrr=min(s[i].x+ss,rrr);
    }
    return l<=rrr;
}

int main()
{
    scanf("%d",&n);
    
    int ff=0,zf=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%lf%lf",&s[i].x,&s[i].y);
        if(s[i].y>0)
            ff=1;
        else
            zf=1;
    }
    if(ff&&zf)
    {
        cout<<-1<<endl;
        return 0;
    }
    if(zf)
        for(int i=1;i<=n;i++)
        {
            s[i].y=-s[i].y;
        }
    
    double ans=1.0*1e16;
    double L=0,R=1e16;
    for(int k=1;k<=100;k++)
    {
        double mid=double(1.0*(L+R))/(2.0);
//        cout<<mid<<endl;
        if(check(mid))
        {
            ans=min(ans,mid);
            R=mid;
        }
        else
            L=mid;
    }
    printf("%.8lf\n",ans);
    
    return 0;
}