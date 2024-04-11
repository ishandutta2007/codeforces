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
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-10
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
const int maxn=500005;
const ll Mod=1000000007;
//const ll Mod=998244353;

struct tmp
{
    int x;
    int id;
    tmp(int a=0,int b=0)
    {
        x=a;
        id=b;
    }
    bool operator<(const tmp& a) const
    {
        return x < a.x; //
    }
};

priority_queue<tmp>q;

int ans[maxn][2];


int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int x;
        while(q.size())
            q.pop();
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            if(x>0)
            {
                q.push(tmp(x,i));
            }
        }
        int cnt=0;
        int u,wu,v,wv;
        while(q.size()>=2)
        {
            u=q.top().id;
            wu=q.top().x;
            q.pop();
            v=q.top().id;
            wv=q.top().x;
            q.pop();
            ans[++cnt][0]=u;
            ans[cnt][1]=v;
            wu--;
            if(wu>0)
                q.push(tmp(wu,u));
            wv--;
            if(wv>0)
                q.push(tmp(wv,v));
        }
        cout<<cnt<<endl;
        for(int i=1;i<=cnt;i++)
            cout<<ans[i][0]<<' '<<ans[i][1]<<endl;
    }
    return 0;
}