#include<bits/stdc++.h>
#define fi first
#define se second
#define mid (l+r>>1)
#define endl '\n'
#define double long double
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;
typedef vector<int>vi;
struct tri {int a, b, c;};
const int N = 2e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll solve()
{
    ll p,q,ret=0;
    cin>>q>>p;
    if(q%p)return q;

    for(ll i=2;i*i<=p;i++)if(p%i==0)
    {
        ll a=1;
        while(p%i==0)
        {
            a*=i;
            p/=i;
        }
        ll t=q;
        while(t%i==0)
        {
            t/=i;
        }
//        cout<<i<<' '<<a<<endl;
        ret=max(ret,t*a/i);
    }
    if(p!=1)
    {
        while(q%p==0)
        {
            q/=p;
        }
//        cout<<q<<endl;
        ret=max(ret,q);
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
//    freopen("in.txt", "r", stdin);
    int _;cin>>_;
    while(_--)
        cout<<solve()<<endl;
    return 0;
}