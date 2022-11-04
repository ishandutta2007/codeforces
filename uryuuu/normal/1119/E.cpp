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
const int maxn=300010;
//const ll Mod=1000000007;
const ll Mod=998244353;

ll a[maxn];

int main()
{
    sync
    int n;
    cin>>n;
    rep(i,1,n)
        cin>>a[i];
    ll sum=0;
    ll s=0;
    ll c;
    ll d=0;
    for(int i=n;i>=1;i--)
    {
        c=1ll*a[i]/2ll;
        s+=1ll*c;
        if(a[i]%2==1&&s)
        {
            s-=1ll;
            sum+=1ll;
        }
    }
    sum+=1ll*s*2ll/3ll;
    cout<<sum<<endl;
    
    return 0;
}