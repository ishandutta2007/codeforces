#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#include<stack>
#include<set>
#include<queue>
#include<map>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=300005,T=100005;

int n,m,a[maxn],L[maxn],R[maxn];
int main()
{
    sync;
    cin>>n>>m;
    if(n==1)
    {
        cout<<0<<endl;
        return 0;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>a[i];
    }
    for(int i=m;i>=1;i--)
    {
        L[i+a[i]+T]=L[i+a[i]+1+T]+1;
        R[a[i]-i+T]=R[a[i]-i-1+T]+1;
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        int l=max(1,i-(m+1)+L[i+T]);
        int r=min(n,i+(m+1)-R[i+T]);
        ans+=1ll*(r-l+1);
    }
    cout<<ans<<endl;
    return 0;
    
}