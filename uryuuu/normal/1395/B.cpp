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
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
//const double pi=acos(-1);
const int maxn = 200010;
//const ll Mod=1000000007;
const ll Mod = 998244353;



int main()
{
    sync;
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    cout<<x<<' '<<y<<endl;
    for(int i=y+1;i<=m;i++)
        cout<<x<<' '<<i<<endl;
    for(int i=y-1;i>=1;i--)
        cout<<x<<' '<<i<<endl;
    int f=0;
    for(int i=1;i<=n;i++)
    {
        if(i==x)
            continue;
        if(f==0)
        {
            for(int j=1;j<=m;j++)
                cout<<i<<' '<<j<<endl;
        }
        else
        {
            for(int j=m;j>=1;j--)
                cout<<i<<' '<<j<<endl;
        }
        f=1-f;
    }
  
    return 0;
}