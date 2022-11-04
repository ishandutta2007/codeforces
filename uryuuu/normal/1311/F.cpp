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
#define lb(x) (x&(-x));
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=200005;
const ll Mod=1000000007;


ll a[maxn],b[maxn];
int n;

struct node
{
    int x,v;
}t[maxn];

void add(int x)
{
    while(x<=n)
    {
        a[x]++;
        x+=lb(x);
    }
}

ll query(int x)
{
    ll s=0;
    while(x>0)
    {
        s+=a[x];
        x-=lb(x);
    }
    return s;
}

bool cmp(node a,node b)
{
    if(a.x==b.x)
        return a.v<b.v;
    return a.x<b.x;
}

int main()
{
    sync;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>t[i].x;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>t[i].v;
        b[i]=t[i].v;
    }
    sort(b+1,b+n+1);
    int cnt=unique(b+1,b+n+1)-b;
    for(int i=1;i<=n;i++)
    {
        int id=lower_bound(b+1,b+cnt,t[i].v)-b;
        t[i].v=id;
    }
    sort(t+1,t+n+1,cmp);
    ll s1=0,s2=0;
    for(int i=1;i<=n;i++)
    {
        s1+=1ll*query(t[i].v)*t[i].x;
        add(t[i].v);
    }
    mm(a);
    ll p=0;
    for(int i=n;i>=1;i--)
    {
//        cout<<t[i].x<<' '<<t[i].v<<' '<<(p-query(t[i].v))<<endl;
        s2+=1ll*(p-query(t[i].v-1))*t[i].x;
        add(t[i].v);
        p++;
    }
    cout<<s1-s2<<endl;
    return 0;
}