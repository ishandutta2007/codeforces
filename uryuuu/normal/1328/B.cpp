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
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'0'))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=100010;
//const ll Mod=1000000007;
const ll Mod=998244353;
using namespace std;



string s;

int main()
{
    sync;
    ll n,k;
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>n>>k;
        for(ll i=max(1ll,(ll)sqrt(1ll*k*2))-1000;i<=min(1ll*n-1,(ll)sqrt(1ll*k*2)+1000);i++)
        if(1ll*i*(i+1)/2<=k&&(1ll*(i+2)*(i+1)/2>k))
        {
            a=i;
            break;
        }
        b=1ll*k-a*(a+1)/2;
        if(b>0)
            a++;
        else
            b=a;
//        cout<<a<<' '<<b<<endl;
        int d=(n-2)-max(0ll,(a-1));
        for(int i=1;i<=d;i++)
            cout<<'a';
        cout<<'b';
        int f=(a-1)-max(0ll,(b-1));
        for(int i=1;i<=f;i++)
            cout<<'a';
        cout<<'b';
        for(int i=1;i<=(n-2-f-d);i++)
            cout<<'a';
        cout<<endl;
    }
    return 0;
}