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
using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=500005;
const ll Mod=1000000007;
//const ll Mod=998244353;

int a[maxn],b[maxn],c[maxn];

int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int cnt=0;
    int x1,x2,y;
    for(int i=1;i<=m;i++)
    {
        cin>>x1>>x2>>y;
        if(x1==1)
        {
            b[++cnt]=x2;
        }
    }
    m=cnt;
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    int ans=m;
    int pos;
    a[n+1]=1e9;
    for(int i=0;i<=n;i++)
    {
        pos=lower_bound(b+1,b+m+1,a[i+1])-b-1;
        c[i]=m-pos+i;
//        cout<<i<<' '<<pos<<' '<<c[i]<<endl;
    }
    
    for(int i=0;i<=n;i++)
    {
        ans=min(c[i],ans);
    }
    cout<<ans<<endl;
    return 0;
}