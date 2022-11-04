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
typedef pair<int,ll> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=5000005;
//const ll Mod=1000000007;
//const ll Mod=998244353;

int a[maxn],f[1<<22];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[a[i]]=a[i];
    }
    for(int i=0;i<=21;i++)
    {
        for(int j=0;j<(1<<22);j++)
        {
            if((j&(1<<i))&&f[j^(1<<i)])
                f[j]=f[j^(1<<i)];
        }
    }
    for(int i=1;i<=n;i++)
    {
        int b=((1<<22)-1)^a[i];
        if(f[b])
            cout<<f[b]<<' ';
        else
            cout<<-1<<' ';
    }
    cout<<endl;
    
    return 0;
}