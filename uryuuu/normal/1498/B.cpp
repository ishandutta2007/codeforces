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
const int maxn=2000005;
//const ll Mod=1000000007;
const ll Mod=998244353;

int a[maxn];
int b[22];
int c[maxn];

int main()
{
    sync;
    int t;
    int n;
    cin>>t;
    b[0]=1;
    for(int i=1;i<=20;i++)
    {
        b[i]=2*b[i-1];
    }
    while(t--)
    {
        int w;
        cin>>n>>w;
        for(int i=0;i<=20;i++)
            c[b[i]]=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            c[a[i]]++;
        }
        int x;
        int ans=0;
        int lv=n;
        int s;
        while(1)
        {
            x=w;
//            cout<<ans<<endl;
            for(int i=20;i>=0;i--)
            {
                s=min(c[b[i]],x/b[i]);
                lv-=s;
                c[b[i]]-=s;
                x-=s*b[i];
            }
            ans++;
//            cout<<lv<<endl;
            if(lv==0)
                break;
        }
        cout<<ans<<endl;
    }
    
    return 0;
}