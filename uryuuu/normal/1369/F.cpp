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
const int maxn=200010;
const ll Mod=1000000007;
//const ll Mod=998244353;

ll s[maxn],e[maxn];
int win(ll s,ll e)
{
    if(e%2)
    {
        if(s%2)
            return 0;
        return 1;
    }
    if(s*2>e)
    {
        if(s%2)
            return 1;
        return 0;
    }
    if(s*4>e)
        return 1;
    return win(s,e/4);
}

int lose(ll s,ll e)
{
    if(s>e/2)
        return 1;
    return win(s,e/2);
}

int main()
{
    sync;
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>s[i]>>e[i];
    }
    int w,l;
    int f=0;
    for(int i=1;i<=t;i++)
    {
        w=win(s[i],e[i]);
        l=lose(s[i],e[i]);
        w^=f;
        l^=f;
        if(w==l)
            break;
        if(w)
            f=1;
        else
            f=0;
    }
    cout<<w<<' '<<l<<endl;
    return 0;
}