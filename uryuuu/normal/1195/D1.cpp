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
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=100005;
//const ll Mod=1000000007;
const ll Mod=998244353;
using namespace std;
 
ll a[maxn];

ll ksm(ll x,ll y)
{
    ll res=1;
    while(y)
    {
        if(y&1)
        {
            res=res*x%Mod;
        }
        x=x*x%Mod;
        y/=2;
    }
    return res%Mod;
}


int main()
{
    sync;
    int n;
    cin>>n;
    ll x;
    ll sum=0;
    ll p;
    ll d;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        p=-1;
        while(x)
        {
            d=x%10;
            p++;
            sum=(sum+1ll*d*((ksm(10,2*p)+ksm(10,2*p+1))%Mod)%Mod+Mod)%Mod;
            x/=10;
//            cout<<ksm(10,2*p)+ksm(10,2*p+1)<<endl;
//            cout<<d<<endl;
        }
    }
    cout<<sum*n%Mod<<endl;
    return 0;
}