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
#define lb(x) (x&(-x));
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=200005;
const ll Mod=1000000007;

ll a[maxn];

int main()
{
    sync;
    ll n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    ll pos=(1+n)/2;
    ll x=1;
    ll s;
    while(pos<n)
    {
        s=x*(a[pos+1]-a[pos]);
        if(k>=s)
        {
            k-=s;
            pos++;
            x++;
        }
        else
        {
            cout<<(a[pos]+(k/x))<<endl;
            return 0;
        }
    }
    cout<<(a[pos]+(k/x))<<endl;
    return 0;
}