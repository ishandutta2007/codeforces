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
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216")  //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
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
const int maxn=10000005;
//const ll Mod=1000000007;
const ll Mod=998244353;

int a[maxn];
int mn[maxn];

int main()
{
    sync;
int aaa;
    int i,x;
    for(i=1;i<maxn;i++)
    {
        x=i;
        while(x<maxn)
        {
            a[x]+=i;
            x+=i;
        }
    }
    for(i=maxn-1;i>=1;i--)
    {
        if(a[i]<maxn)
            mn[a[i]]=i;
    }
    
    int t;
    cin>>t;
    while(t--)
    {
        int c;
        cin>>c;
        if(mn[c]==0)
            cout<<-1<<endl;
        else
            cout<<mn[c]<<endl;
    }
    
    return 0;
}