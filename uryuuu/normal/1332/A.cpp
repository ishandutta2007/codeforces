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
#define ch(a) (int(a-'0'))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=200010;
const ll Mod=1000000007;
//const ll Mod=998244353;
using namespace std;




int  main()
{
    sync;
    int n,t;
    ll l,r,d,u;
    ll x,y,x1,y1,x2,y2;
    cin>>t;
    while(t--)
    {
        cin>>l>>r>>d>>u;
        cin>>x>>y>>x1>>y1>>x2>>y2;
        if(x1==x2&&(l+r))
        {
            cout<<"No"<<endl;
            continue;
        }
        if(y1==y2&&(u+d))
        {
            cout<<"No"<<endl;
            continue;
        }
        ll w=min(l,r);
        l-=w;
        r-=w;
        w=min(u,d);
        u-=w;
        d-=w;
        if(x-l+r<=x2&&x-l+r>=x1&&y-d+u>=y1&&y-d+u<=y2)
        {
            cout<<"Yes"<<endl;
        }
        else
            cout<<"No"<<endl;
    }
    
    return 0;
}