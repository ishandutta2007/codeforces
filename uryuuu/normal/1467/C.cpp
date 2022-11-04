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
const ll Mod=1000000007;
//const ll Mod = 998244353;

ll a[maxn],b[maxn],c[maxn];

int main()
{
    sync;
    int ant,bnt,cnt;
    ll prea=0;
    ll preb=0;
    ll prec=0;
    cin>>ant>>bnt>>cnt;
    for(int i=1;i<=ant;i++)
    {
        cin>>a[i];
        prea+=a[i];
    }
    for(int i=1;i<=bnt;i++)
    {
        cin>>b[i];
        preb+=b[i];
    }
    for(int i=1;i<=cnt;i++)
    {
        cin>>c[i];
        prec+=c[i];
    }
    
    sort(a+1,a+ant+1);
    sort(b+1,b+bnt+1);
    sort(c+1,c+cnt+1);
    ll mx=-2e18;
    mx=max(prea+preb-prec,mx);
    mx=max(prec+preb-prea,mx);
    mx=max(prea+prec-preb,mx);
    prea+=preb;
    prea+=prec;
    mx=max(prea-2ll*(a[1]+b[1]),mx);
    mx=max(prea-2ll*(c[1]+b[1]),mx);
    mx=max(prea-2ll*(a[1]+c[1]),mx);
    cout<<mx<<endl;
    return 0;
}