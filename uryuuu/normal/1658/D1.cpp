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

int a[maxn];
int ans[maxn];

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int n,x,ans=0;
        cin>>n;
        cin>>n;
        for(int i=0;i<=n;i++)
        {
            cin>>a[i];
        }
        int pre,suc;
        for(int k=0;k<=19;k++)
        {
            x=(1<<k);
            pre=0;suc=0;
            for(int i=0;i<=n;i++)
            {
                if(a[i]&x)
                    suc++;
                if(i&x)
                    pre++;
            }
            if(pre!=suc)
                ans+=x;
        }
//        for(int i=0;i<=n;i++)
//        {
//            cout<<(a[i]^ans)<<' ';
//        }
        cout<<ans<<endl;
    }
    
//    for(int x=0;x<=10;x++)
//    {
//        cout<<"F"<<x<<' ';
//        for(int i=0;i<=n;i++)
//        {
//            cout<<(i^x)<<' ';
//        }
//        cout<<endl;
//    }
    
    return 0;
}