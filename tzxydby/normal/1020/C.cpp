#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e3+10;
struct node{
    ll val;
    int x,id;
}a[maxn];
node b[maxn];
int n,book[maxn],m;
vector<node>s[maxn];
bool cmp(const node &x,const node&y)
{
    return x.val<y.val;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%I64d",&a[i].x,&a[i].val);
        b[i]=a[i];
        b[i].id=i;
        node g;
        g.id=i;
        g.val=a[i].val;
        s[a[i].x].push_back(g);
    }
    sort(b+1,b+n+1,cmp);
    for(int i=1;i<=m;i++)
        sort(s[i].begin(),s[i].end(),cmp);
    ll ans=1e15;
    for(int k=0;k<=n;k++)
    {
        ll tmp=0;
        int nu=s[1].size();
        memset(book,0,sizeof book);
        for(int i=2;i<=m;i++)
        {
            if(s[i].size()>k)
            {
                for(int j=0;j<s[i].size()-k;j++)
                {
                    int ii=s[i][j].id;
                    tmp+=a[ii].val;
                    book[ii]=1;
                    nu++;
                }
            }
        }
        if(nu<=k)
        {
            for(int i=1;i<=n;i++)
            {
                if(nu<=k)
                {
                    if(b[i].x!=1&&!book[b[i].id])
                    {
                        tmp+=b[i].val;
                        nu++;
                    }
                }
                else
                    break;
            }
        }
        ans=min(ans,tmp);
    }
    printf("%I64d\n",ans);
    return 0;
}