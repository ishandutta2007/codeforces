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
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=200010;
//const ll Mod=1000000007;
const ll Mod=998244353;
using namespace std;

struct node
{
    ll num,cost,id;
}a[maxn];

bool cmp(node a,node b)
{
    if(a.cost==b.cost)
        return a.id<b.id;
    return a.cost<b.cost;
}

int pos[maxn];

int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].num;
        a[i].id=i;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].cost;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        pos[a[i].id]=i;
    }
    
//    for(int i=1;i<=n;i++)
//    {
//        cout<<a[i].cost<<' ';
//    }
//    cout<<endl;
//    for(int i=1;i<=n;i++)
//    {
//        cout<<a[i].num<<' ';
//    }
//    cout<<endl;
//    for(int i=1;i<=n;i++)
//    {
//        cout<<a[i].id<<' ';
//    }
//    cout<<endl;
    
    
    int lst=1;
    ll sum;
    int t;
    ll d;
    int f=0;
    while(m--)
    {
        cin>>t>>d;
        if(f==1)
        {
            cout<<0<<endl;
            continue;
        }
        sum=0;
        int id=pos[t];
        if(a[id].num>=d)
        {
//            cout<<a[id].num<<endl;
            sum=1ll*d*a[id].cost;
            cout<<sum<<endl;
            a[id].num-=d;
            continue;
        }
        sum=1ll*a[id].num*a[id].cost;
        d-=a[id].num;
        a[id].num=0;
//        cout<<sum<<' '<<d<<' ';
        while(lst<=n)
        {
            if(a[lst].num>=d)
            {
                sum+=1ll*d*a[lst].cost;
                a[lst].num-=d;
                d=0;
                break;
            }
            sum+=1ll*a[lst].num*a[lst].cost;
            d-=a[lst].num;
            a[lst].num=0;
//            cout<<sum<<' '<<d<<' '<<lst<<' ';
            lst++;
            if(d==0)
                break;
        }
        if(lst>n)
            f=1;
        if(d==0)
        {
            cout<<sum<<endl;
        }
        else
        {
            cout<<0<<endl;
            f=1;
        }
    }
    
    return 0;
}