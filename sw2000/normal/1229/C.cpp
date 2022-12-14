#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
ll ans;

struct E
{
    ll l,r;
    vector<int>v;
}e[maxn];

void f(int a)
{
    for(int i=0;i<e[a].r;i++)
    {
        int b=e[a].v[i];
        ans-=e[b].l*e[b].r;
        e[b].l--;
        e[b].r++;
        e[b].v.push_back(a);
        ans+=e[b].l*e[b].r;
    }
    ans-=e[a].l*e[a].r;
    e[a].l+=e[a].v.size();
    e[a].r=0;
    e[a].v.clear();
}

int main()
{
    int n,m,q;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(b<a)swap(b,a);
        e[a].v.push_back(b);
        e[a].r++;
        e[b].l++;
    }
    for(int i=1;i<=n;i++)
    {
        ans+=(ll)e[i].r*e[i].l;
    }
    printf("%lld\n",ans);
    scanf("%d",&q);
    while(q--)
    {
        int v;
        scanf("%d",&v);
        f(v);
        printf("%lld\n",ans);
    }
}