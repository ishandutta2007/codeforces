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
struct node
{
    int id,v;
}a[2005];
bool cmp(node a,node b)
{
    return a.v<b.v;
}
ll s;
int main()
{
    sync;
    int t;
    int n,m;
    cin>>t;
    while(t--)
    {
        s=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].v;
            s+=a[i].v;
            a[i].id=i;
        }
        if(m<n||n==2)
        {
            cout<<-1<<endl;
            continue;
        }
        s*=2;
        sort(a+1,a+n+1,cmp);
        s+=(a[1].v+a[2].v)*(m-n);
        cout<<s<<endl;
        for(int i=1;i<n;i++)
        {
            cout<<i<<' '<<i+1<<endl;
        }
        cout<<1<<' '<<n<<endl;
        for(int i=1;i<=m-n;i++)
        {
            cout<<min(a[1].id,a[2].id)<<' '<<max(a[1].id,a[2].id)<<endl;
        }
    }
    return 0;
}