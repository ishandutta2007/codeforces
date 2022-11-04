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
#include <chrono>
#include <random>
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
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
#define umap(a) (a).reserve(1024);(a).max_load_factor(0.25);
using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=5000005;
const ll Mod=1000000007;
//const ll Mod=998244353;

struct node
{
    int id,val;
}a[520];



struct nod
{
    int u,v,w;
}q[maxn];

bool cmp(nod a,nod b)
{
    return a.w>b.w;
}

string s;

int main()
{
    sync;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].val;
        a[i].id=i;
    }
    
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            q[++cnt].u=i;
            q[cnt].v=j;
            q[cnt].w=abs(a[i].val-a[j].val);
            if(a[i].val>a[j].val)
                swap(q[cnt].u,q[cnt].v);
        }
    }
    
    sort(q+1,q+cnt+1,cmp);
    for(int i=1;i<=cnt;i++)
    {
        s="";
        cout<<"? "<<q[i].v<<' '<<q[i].u<<endl;
        cin>>s;
        if(s[0]=='Y')
        {
            cout<<"! "<<q[i].v<<' '<<q[i].u<<endl;
            return 0;
        }
    }
    cout<<"! 0 0"<<endl;
    return 0;
}