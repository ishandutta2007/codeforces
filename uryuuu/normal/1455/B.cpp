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
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=500010;  // 
//const ll Mod=1000000007;
const ll Mod = 998244353;


ll b[maxn];

int main()
{
    sync;
    int t;
    int n;
    for(int i=0;i<=10000;i++)
    {
        b[i]=1ll*i;
    }
    for(int i=1;i<=10000;i++)
    {
        b[i]=1ll*b[i-1]+b[i];
    }
    cin>>t;
    while(t--)
    {
        ll x;
        cin>>x;
        ll id=lower_bound(b+1,b+9999,x)-b;
//        cout<<id<<' '<<x<<' '<<b[id]<<endl;
        if(b[id]==x+1)
            id=id+1;
            
        cout<<id<<endl;
        
    }
    
    
    
    return 0;
}