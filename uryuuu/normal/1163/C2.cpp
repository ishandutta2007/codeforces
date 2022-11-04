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
const int maxn=100010;
//const ll Mod=1000000007;
const ll Mod=998244353;


map<double,int>mp;
double x[1005],y[1005];
map<pair<double,double>,int>vis;


int main()
{
    sync;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i]>>y[i];
    }
    ll s=0;
    double w,h;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(x[j]!=x[i])
            {
                w=1.0*(1.0*y[j]-1.0*y[i])/(1.0*x[j]-1.0*x[i]);
                h=1.0*y[i]-1.0*w*x[i];
            }
            else
            {
                w=1000000.0;
                h=1.0*x[i];
            }
            if(vis[make_pair(w,h)]==0)
            {
                vis[make_pair(w,h)]++;
                mp[w]++;
                s++;
            }
        }
    }
    ll sum=0;
    for(auto f:mp)
    {
        sum+=1ll*f.second*(s-f.second);
    }
    sum/=2ll;
    cout<<sum<<endl;
    return 0;
}