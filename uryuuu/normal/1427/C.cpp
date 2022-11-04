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
const int maxn=500010;  // 
const ll Mod=1000000007;
//const ll Mod = 998244353;

struct node
{
    int x,y,t;
}a[maxn];

int dp[505][505];
vector<node>g[maxn];

int main()
{
    sync;
    int r,n;
    cin>>r>>n;
    int mx=0;
    int s,d;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].t>>a[i].x>>a[i].y;
        if(a[i].x-1+a[i].y-1>a[i].t)
        {
            continue;
        }
        s=1;
        d=mx;
        for(int j=d;j>=1;j--)
        {
            for(auto v:g[j])
            {
                if(abs(v.x-a[i].x)+abs(v.y-a[i].y)<=a[i].t-v.t)
                {
                    s=j+1;
                    break;
                }
            }
            if(s>1)
                break;
        }
        mx=max(s,mx);
        g[s].push_back(a[i]);
    }
    cout<<mx<<endl;
    
    return 0;
}