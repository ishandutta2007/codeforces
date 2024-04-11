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
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'A')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=500005;
const ll Mod=1000000007;
//const ll Mod=998244353;
//typedef pair<pii,int> piii;


string s;

int main()
{
    sync;
    int n;
    ll x,y;
    cin>>n>>x>>y;
    cin>>s;
    ll k=0ll;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
            if(i==0||s[i-1]=='1')
                k++;
        }
    }
    ll sum=1ll*k*y;
    if(k>0)
    {
        sum=1ll*sum-(1ll*k-1ll)*max(0ll,y-x);
    }
    cout<<sum<<endl;
    return 0;
}