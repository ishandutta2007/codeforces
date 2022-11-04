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
//#pragma comment(linker, "/STACK:36777216") //hdu 
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
const int maxn=500005;
const ll Mod=1000000007;
//const ll Mod=998244353;

string s;

ll gcd(ll a,ll b)
{
    if(a==0)
        return 1ll;
    if(a<0)
        return gcd(-a,b);
    while(b)
    {
        ll t=a%b;
        a=b;
        b=t;
    }
    return a;
}

int pred[maxn];
map<pii,int>dp;

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        s="";
        cin>>s;
        int d=0,k=0;
        int gd;
        int dd,kk;
        dp.clear();
        for(int i=0;i<n;i++)
        {
            pred[i+1]=pred[i];
            if(s[i]=='D')
            {
                d++;
                pred[i+1]++;
            }
            else
                k++;
            
            if(d==0)
            {
                cout<<k<<' ';
                continue;
            }
            if(k==0)
            {
                cout<<d<<' ';
                continue;
            }
           
            gd=gcd(d,k);
            dd=d/gd;
            kk=k/gd;
            dp[mkp(dd,kk)]++;
            cout<<dp[mkp(dd,kk)]<<' ';
            
        }
        cout<<endl;
    }
    return 0;
}