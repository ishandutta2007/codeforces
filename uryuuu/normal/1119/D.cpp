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
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'A')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=200010;
//const ll Mod=1000000007;
const ll Mod=998244353;

ll a[maxn],s[maxn],d[maxn];

int main()
{
    sync
    int n;
    cin>>n;
    rep(i,1,n)
        cin>>a[i];
    sort(a+1,a+n+1);
    rep(i,1,n-1)
    {
        d[i]=a[i+1]-a[i];
    }
    sort(d,d+n);
    s[0]=0;
    for(int i=1;i<n;i++)
    {
        s[i]=1ll*d[i]+1ll*s[i-1];
    }
    int q;
    cin>>q;
    ll L,R;
    ll len;
    ll sum;
    int pos;
    while(q--)
    {
        cin>>L>>R;
        len=R-L+1;
        sum=1ll*len*n;
        pos=lower_bound(d+1,d+n,len)-d;
        sum=1ll*sum-1ll*(pos-1)*len+1ll*s[pos-1];
        cout<<sum<<' ';
//        cout<<L<<' '<<R<<' '<<sum;
    }
    cout<<endl;
    return 0;
}