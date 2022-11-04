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
int dd[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
using namespace std;
const int maxn=200010;
ll b[maxn];
struct node
{
    ll v;
    ll id;
}a[maxn];
int cmp(node a,node b)
{
    return a.v*a.id>b.v*b.id;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].v;
        a[i].id=(1ll*i*(n-i+1));
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    sort(a+1,a+n+1,cmp);
    sort(b+1,b+n+1);
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        sum=(sum+1ll*(a[i].v*a[i].id%998244353)*b[i]%998244353)%998244353;
    }
    cout<<sum<<endl;
    return 0;
}