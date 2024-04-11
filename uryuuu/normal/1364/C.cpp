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
#define mkp(a,b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=1000010;
//const ll Mod=1000000007;
const ll Mod=998244353;


int a[maxn];
int b[maxn];
int v[maxn];
int vis[maxn];

int main()
{
    sync;
    int n;
    cin>>n;
    rep(i,1,n)
        cin>>a[i];
    
    memset(b,-1,sizeof(b));
    
    vis[a[n]]=1;
    for(int i=n-1;i>=1;i--)
    {
        if(a[i]!=a[i+1])
        {
            b[i+1]=a[i];
            vis[a[i]]=1;
        }
    }
    
    if(a[1]==1)
    {
        b[1]=0;
        vis[0]=1;
    }
    
    int d=0;
    
    for(int i=1;i<=n;i++)
    {
        if(b[i]==-1)
        {
            while(vis[d])
                d++;
            b[i]=d++;
        }
    }
    
    
    for(int i=1;i<=n;i++)
        cout<<b[i]<<' ';
    cout<<endl;
    
    return 0;
}