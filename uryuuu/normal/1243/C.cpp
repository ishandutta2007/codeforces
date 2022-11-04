#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
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
int a[30];
struct node
{
    int l,r;
}b[400];
int main()
{
    sync;
    ll n;
    cin>>n;
    ll x;
    int f=0;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            x=i;
            f=1;
            break;
        }
    }
    if(f==0)
    {
        cout<<n<<endl;
        return 0;
    }
    while(n%x==0)
    {
        n/=x;
    }
    if(n==1)
        cout<<x<<endl;
    else
        cout<<1<<endl;
    return 0;
}