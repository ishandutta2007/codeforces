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
//typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=200005;
//const ll Mod=1000000007;
const ll Mod=998244353;

string s;
ll pre[105];
ll L[105],R[105];

char dfs(ll pos,int dep)
{
//    cout<<pos<<' '<<dep<<endl;
    if(dep==0)
    {
//        cout<<pos<<endl;
        return s[pos-1];
    }
    if(pos>pre[dep-1])
        return dfs(L[dep]+pos-pre[dep-1]-1ll,dep-1);
    return dfs(pos,dep-1);
}

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        s="";
        int n,c,q;
        cin>>n>>c>>q;
        cin>>s;
        pre[0]=s.length();
        int m=0;
        for(int i=1;i<=c;i++)
        {
            cin>>L[i]>>R[i];
        }
        for(int i=1;i<=c;i++)
        {
            pre[i]=pre[i-1]+1ll*(R[i]-L[i]+1ll);
            m++;
            if(pre[i]>3e18)
                break;
        }
        ll x;
        while(q--)
        {
            cin>>x;
            cout<<dfs(x,m)<<'\n';
        }
        
    }
    return 0;
}