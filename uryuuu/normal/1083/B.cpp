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
#define flush fflush(stdout)
using namespace std;
typedef pair<int,ll> pii;
const double pi=acos(-1);
const int maxn=300010;
const ll Mod=1000000007;
//const ll Mod = 998244353;
//#define int long long


string s,t;

int main()
{
    sync;
    int n;
    ll k;
    cin>>n>>k;
    cin>>s>>t;
    ll ans=0;
    ll sum=0;
    ll pre=1ll;
    for(int i=0;i<n;i++)
    {
        sum=2ll*pre;
        if(s[i]=='b')
            sum--;
        if(t[i]=='a')
            sum--;
        ans=1ll*ans+min(sum,k);
        pre=min(sum,k+1000ll);
        
    }
    cout<<ans<<endl;
    
    return 0;
}