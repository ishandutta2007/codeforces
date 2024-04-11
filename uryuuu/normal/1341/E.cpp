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
const int maxn=1000010;
//const ll Mod=1000000007;
const ll Mod=998244353;

int dp[10005][1005];
int p[10005];

int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    int g,r;
    rep(i,1,m)
    {
        cin>>p[i];
    }
    cin>>g>>r;
    sort(p+1,p+m+1);
    deque<pii>q;
    memset(dp,inf,sizeof(dp));
    dp[1][g]=0;
    q.push_back(pii(1,g));
    int id,d;
    int x;
    while(q.size())
    {
        id=q.front().first;
        d=q.front().second;
        q.pop_front();
        if(id>1)
        {
            if(p[id]-p[id-1]<d)
            {
                if(dp[id-1][d-(p[id]-p[id-1])]>dp[id][d])
                {
                    dp[id-1][d-(p[id]-p[id-1])]=dp[id][d];
                    q.push_front(pii(id-1,d-(p[id]-p[id-1])));
                }
            }
            else if(p[id]-p[id-1]==d)
            {
                if(dp[id-1][g]>dp[id][d]+1)
                {
                    dp[id-1][g]=dp[id][d]+1;
                    q.push_back(pii(id-1,g));
                }
            }
        }
        if(id<m)
        {
            if(p[id+1]-p[id]<d)
            {
                if(dp[id+1][d-(p[id+1]-p[id])]>dp[id][d])
                {
                    dp[id+1][d-(p[id+1]-p[id])]=dp[id][d];
                    q.push_front(pii(id+1,d-(p[id+1]-p[id])));
                }
            }
            else if(p[id+1]-p[id]==d)
            {
                if(dp[id+1][g]>dp[id][d]+1)
                {
                    dp[id+1][g]=dp[id][d]+1;
                    q.push_back(pii(id+1,g));
                }
            }
        }
    }
    ll zd=2e18;
//    for(int i=1;i<m;i++)
//    {
//        cout<<i<<' '<<dp[i][g]<<endl;;
//    }
    for(int i=1;i<m;i++)
    {
        if(p[m]-p[i]<=g&&dp[i][g]<inf)
        {
//            cout<<dp[i][g]<<' ';
            zd=min(1ll*dp[i][g]*(g+r)+p[m]-p[i],zd);
        }
    }
    if(zd==2e18)
        cout<<-1<<endl;
    else
        cout<<zd<<endl;
    
    
    return 0;
}