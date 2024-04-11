
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forij for(int i=1;i<=m;++i)
#define forjj for(int j=1;j<=m;++j)
#define int ll
struct node
{
    int v,id;
    bool operator < (const node & n) const
    {
        return v<n.v;
    }
}a[200005];
int32_t main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    if(n<=3) {cout<<1<<endl;return 0;}
    forii cin>>a[i].v,a[i].id=i;
    sort(a+1,a+1+n);
    int d=a[2].v-a[1].v;
    int nxt=a[1].v,cnt=0,idx=n;
    for(int i=1;i<=n;++i)
    {
        if(a[i].v!=nxt) ++cnt,idx=i;
        else nxt+=d;
    }
    if(cnt<=1)
    {
        cout<<a[idx].id<<endl;
        return 0;
    }
    d=a[3].v-a[1].v;
    nxt=a[1].v,cnt=0;
    for(int i=1;i<=n;++i)
    {
        if(a[i].v!=nxt) ++cnt;
        else nxt+=d;
    }
    if(cnt<=1)
    {
        cout<<a[2].id<<endl;
        return 0;
    }
    d=a[3].v-a[2].v;
    nxt=a[2].v,cnt=0;
    for(int i=2;i<=n;++i)
    {
        if(a[i].v!=nxt) ++cnt;
        else nxt+=d;
    }
    if(!cnt)
    {
        cout<<a[1].id<<endl;
        return 0;
    }
    cout<<-1<<endl;
}