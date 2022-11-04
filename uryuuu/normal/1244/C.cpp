#include<iostream>
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
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=500005;
 
const ll Mod=1000000007;
 

int main()
{
    sync;
    ll n,p,w,d;
    cin>>n>>p>>w>>d;
    for(ll y=0;y<w;y++)
    {
        if(p-y*d<0)
        {
            cout<<-1<<endl;
            return 0;
        }
        if((p-y*d)%w==0)
        {
            ll x=(p-y*d)/w;
            if(x+y>n)
                cout<<-1<<endl;
            else
                cout<<x<<' '<<y<<' '<<n-x-y<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}