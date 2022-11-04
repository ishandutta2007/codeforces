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
#include <functional>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define tm(a,b,c) max(max(a,b),c)
#define inf 0x3f3f3f3f
const ll Mod=1e9+7;
#define maxn 11000
using namespace std;
ll a[200005],b[200005];
int dd[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int main()
{
    ll ta,tb;
    int n,m,k;
    cin>>n>>m>>ta>>tb>>k;
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        a[i]+=ta;
    }
    for(int i=0;i<m;i++)
    {
        scanf("%lld",&b[i]);
    }
    if(k>=m||k>=n)
    {
        cout<<-1<<endl;
        return 0;
    }
    ll sum=0;
    int zz=lower_bound(b,b+m,a[0])-b;
    int zd=zz+k;
    for(int i=1;i<=k;i++)
    {
        int z=lower_bound(b,b+m,a[i])-b;
        zd=max(zd,z+k-i);
        if(zd>m-1)
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    sum=b[zd]+tb;
    cout<<sum<<endl;
    return 0;
}