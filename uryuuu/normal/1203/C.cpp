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
#define maxn 500010
using namespace std;
ll a[400005];
ll gcd(ll a, ll b)
{
    return b ? gcd(b, a%b) : a;
}
int main()
{
    sync
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<n;i++)
    {
        a[i]=gcd(a[i],a[i-1]);
    }
    ll sum=0;
    ll s=sqrt(a[n-1]);
    for(ll i=1;i<=s;i++)
    {
        if(a[n-1]%i==0)
            sum++;
    }
    sum*=2;
    if(s*s==a[n-1])
        sum--;
    cout<<sum<<endl;
    return 0;
}