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
#define ll long long
#define N 500005
#define M 25
#define mod 1000000007
int inf=0x3f3f3f3f;
using namespace std;
const int maxn=1e5+7;
struct node
{
    ll a,b;
}x[maxn];
bool cmp(node q,node w)
{
    return q.b-q.a<w.b-w.a;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%lld%lld",&x[i].a,&x[i].b);
    sort(x+1,x+n+1,cmp);
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=x[i].a*(i-1)+x[i].b*(n-i);
    }
    cout<<ans<<endl;
    return 0;
}