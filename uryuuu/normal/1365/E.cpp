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
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216")  //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=300010;
const ll Mod=1000000007;
//const ll Mod = 998244353;


ll a[600];

int main()
{
    sync;
    int n;
    cin>>n;
    rep(i,1,n)
    cin>>a[i];
    ll ans=0ll;
    if(n<=3)
    {
        for(int i=1;i<=n;i++)
            ans=ans|a[i];
        cout<<ans<<endl;
        return 0;
    }
    ll s;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(int k=j+1;k<=n;k++)
            {
                s=0ll;
                s=s|a[i];
                s=s|a[j];
                s=s|a[k];
                ans=max(ans,s);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}