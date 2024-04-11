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
const int maxn=500010;
//const ll Mod=1000000007;
const ll Mod=998244353;


string s;
ll pre[2000];

int main()
{
    sync;
    pre[1]=1ll;
    for(ll i=2;i<=1000;i++)
    {
        pre[i]=1ll*pre[i-1]*i%Mod*i%Mod;
    }
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        if(n%2)
            cout<<0<<'\n';
        else
            cout<<pre[n/2]<<'\n';
        
//        ll sum=1ll;
//        for(ll i=1ll;i<=10000000ll;i++)
//        {
//            sum=sum*i%Mod*i%Mod;
//            if(sum==665702330)
//                cout<<i<<endl;
//        }
    }
    return 0;
}