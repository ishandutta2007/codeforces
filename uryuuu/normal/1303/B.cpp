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


string s;

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        ll n,g,b;
        cin>>n>>g>>b;
        ll d=n/2;
        ll a=d/b;
        if((g+b)*a+g+d%b>=n)
        {
            cout<<n<<endl;
            continue;
        }
        
        ll s=(g+b)*a;
        n-=s;
        if(d%b)
        {
            s+=g+b;
            n-=g;
            n-=d%b;
        }
        ll x=(n/g);
        if(n%g)
        {
            x++;
        }
        x=max(0ll,x-1);
        s+=(x*(g+b)+n-x*g);
        cout<<s<<endl;
    }
    return 0;
}