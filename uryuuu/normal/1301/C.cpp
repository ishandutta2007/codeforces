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
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=100005;
const ll Mod=1000000007;


int a[maxn];

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        ll s=(n+1)*n/2ll;
        ll d=n-m;
        ll k=d/(m+1);//meikuai
        ll g=d%(m+1);//yu
//        cout<<k<<' '<<g<<' '<<m<<endl;
        ll xx=m+1-g;
        s-=xx*((k+1ll)*k/2ll);
        if(g)
            s-=g*((k+2ll)*(k+1)/2ll);
        cout<<1ll*s<<endl;
    }
    
    return 0;
}