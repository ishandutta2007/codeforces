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
#define ch(a) (int(a-'A')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=300010;
//const ll Mod=1000000007;
const ll Mod=998244353;


struct node
{
    ll t,b;
}s[maxn];

bool cmp(node a,node c)
{
    return a.b>c.b;
}

priority_queue<ll,vector<ll>,greater<ll> > q;

int main()
{
    sync;
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i].t>>s[i].b;
    }
    sort(s+1,s+n+1,cmp);
    ll sum=0ll;
    ll zd=0ll;
    for(int i=1;i<=n;i++)
    {
        sum=sum+1ll*s[i].t;
        zd=max(zd,1ll*sum*s[i].b);
        q.push(s[i].t);
        if(q.size()>=k)
        {
            sum-=1ll*q.top();
            q.pop();
        }
    }
    cout<<zd<<endl;
    
    return 0;
}