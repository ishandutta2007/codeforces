#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define X first
#define Y second
#define mp make_pair
#define ph push
#define pb push_back
#define rep(i,a,n) for (int i = a; i <= n; ++i)
#define dep(i,a,n) for (int i = a; i >= n; --i)
#define re(b,a) for(a::iterator it=b.begin();it!=b.end();++it)
#define clr(a,b) memset(a,sizeof(a),b);
#define inf 0x7fffffff
#define eps 1e-8
using namespace std;
typedef long long ll;
typedef double lf;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<lf,lf> pff;
const int N=111111;
int l,m,n,t,cur;
lf V;
inline void read(int &n)
{
    char c;
    for (c = getchar(); !(c >= '0' && c <= '9'); c = getchar());
    n = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar()) n = n * 10 + c - '0';
}
struct fdd{lf agl,ans1,ans2;int num;}a[N];
struct fdd2{lf x,y;}b[N];
bool cmp(const fdd &a,const fdd &b){return a.agl<b.agl||a.agl==b.agl&&a.num<b.num;}
bool cmp2(const fdd &a,const fdd &b){return a.num<b.num;}
bool cmp3(const fdd2 &a,const fdd2 &b){return a.x<b.x;}
lf jiao(lf x,lf cur){return cur*tan(x)-4.9/V/V*(1+tan(x)*tan(x))*cur*cur;}
lf beng(lf x){return tan(x)/4.9*V*V/(1+tan(x)*tan(x));}
/*
xi[cur]*tan(x)-4.9/V/V*(1+tan(x)*tan(x))*xi[cur]*xi[cur]=0
xi[cur]*tan(x)=4.9/V/V*(1+tan(x)*tan(x))*xi[cur]*xi[cur]
tan(x)=4.9/V/V*(1+tan(x)*tan(x))*xi[cur]
xi[cur]=tan(x)/(4.9/V/V*(1+tan(x)*tan(x)))
xi[cur]=tan(x)/4.9*V*V/(1+tan(x)*tan(x))
*/
int main()
{
    scanf("%d%lf",&n,&V);rep(i,1,n)scanf("%lf",&a[i].agl),a[i].num=i;
    scanf("%d",&m);rep(i,1,m)scanf("%lf%lf",&b[i].x,&b[i].y);b[++m].x=inf;b[m].y=0;
    sort(a+1,a+1+n,cmp);cur=1;sort(b+1,b+1+m,cmp3);
    rep(i,1,n)
    {
        while(jiao(a[i].agl,b[cur].x)-b[cur].y>eps)++cur;
        //printf("%d %.3lf %.3lf %.3lf\n",cur,a[i].agl,b[cur].x,jiao(a[i].agl,b[cur].x));
        if(jiao(a[i].agl,b[cur].x)-0>eps)
            a[i].ans1=b[cur].x,a[i].ans2=jiao(a[i].agl,b[cur].x);
        else a[i].ans1=beng(a[i].agl),a[i].ans2=0;
        //printf("%.3lf\n",beng(a[i].agl));
    }sort(a+1,a+1+n,cmp2);
    rep(i,1,n)printf("%.8lf %.8lf\n",a[i].ans1,a[i].ans2);
    return 0;
}