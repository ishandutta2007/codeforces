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
const int maxn=200005;

const long long Mod=1e9+7;
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
    return res;
}
int a[305][305];
int main()
{
    sync
    int n;
    cin>>n;
    int d;
    for(int i=0;i<n;i++)
    {
        if(i%2)
        for(int j=1;j<=n;j++)
        {
            a[n-j+1][i+1]=n*i+j;
        }
        else
        for(int j=1;j<=n;j++)
        {
            a[j][i+1]=n*i+j;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<a[i][j]<<' ';
        cout<<endl;
            }
    return 0;
}