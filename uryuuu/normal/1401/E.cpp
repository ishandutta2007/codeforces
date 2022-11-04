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
//#include<map>
#include<bitset>
//#include<unordered_map>
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
const int maxn=1000010;
const ll Mod=1000000007;
//const ll Mod = 998244353;

ll a[maxn];

struct node
{
    int x,dn,up;
}Y[maxn];

struct nod
{
    int x,val,fl;
}X[maxn];

bool cmp(node a,node b)
{
    return a.x<b.x;
}

bool cp(nod a,nod b)
{
    return a.x<b.x;
}

void add(int x,int val)
{
    while(x<maxn)
    {
        a[x]+=val;
        x+=lb(x);
    }
}

ll query(int x)
{
    ll ans=0;
    while(x)
    {
        ans+=a[x];
        x-=lb(x);
    }
    return ans;
}

int main()
{
    sync;
    int n;
    cin>>n;
    int m;
    cin>>m;
    int h,l,r;
    ll sum=1;
    for(int i=1;i<=n;i++)
    {
        cin>>h>>l>>r;
        X[2*i-1]={l,h+1,1};
        X[2*i]={r+1,h+1,-1};
        if(l==0&&r==1000000)
            sum++;

    }
    
    for(int i=1;i<=m;i++)
    {
        cin>>Y[i].x>>Y[i].dn>>Y[i].up;
    }
    
    sort(X+1,X+2*n+1,cp);
    sort(Y+1,Y+m+1,cmp);
    
    int pos=1;
    add(1,1);
    add(1000001,1);
    for(int i=1;i<=m;i++)
    {
        while(pos<=2*n&&X[pos].x<=Y[i].x)
        {
            add(X[pos].val,X[pos].fl);
            pos++;
        }
        sum+=1ll*query(Y[i].up+1)-query(Y[i].dn)-1;
    }
    cout<<sum<<endl;
    return 0;
}