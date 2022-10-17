
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forjj for(int j=1;j<=m;++j)
#define forij for(int i=1;i<=m;++i)

int a[100005],b[100005];
struct p {
    int x,y;
    bool operator < (const p & t) const
    {
        return x<t.x;
    }
}c[100005];
int sum[100005],ans[100005];
int main()
{
    int n,m;
    cin>>n>>m;
    forii cin>>a[i];
    forij cin>>c[i].x>>c[i].y;
    sort(c+1,c+1+m);
    forij sum[i]=sum[i-1]+c[i].y;
    forii
    {
        int pos=upper_bound(c+1,c+1+m,p{a[i],1000000000})-c-1;
        if(c[pos].x>a[i]) pos--;
        ans[i]=sum[pos];
    }
    forii cout<<ans[i]<<" ";cout<<endl;
}