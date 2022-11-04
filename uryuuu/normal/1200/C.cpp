#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<set>
#include<map>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define maxn 300050
using namespace std;
ll gcd(ll a, ll b)
{
    return b ? gcd(b, a%b) : a;
}
int main()
{
    ll n,m,q;
    ll sx,sy,ex,ey;
    cin>>n>>m>>q;
    ll b=gcd(n,m);
    ll nz=n/b,mz=m/b;
    ll ss,ee;
//    cout<<b<<' '<<nz<<' '<<mz<<endl;
    while(q--)
    {
        scanf("%lld%lld%lld%lld",&sx,&sy,&ex,&ey);
        sy--;
        ey--;
        if(sx==1)
            ss=sy/nz;
        else
            ss=sy/mz;
        if(ex==1)
            ee=ey/nz;
        else
            ee=ey/mz;
//        cout<<ss<<' '<<ee;
        if(ss==ee)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}