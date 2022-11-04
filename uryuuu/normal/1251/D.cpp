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
#include<unordered_map>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define pii pair<int,int>
using namespace std;
const ll Mod=1e9+7;
const int maxn=200005;
string s;
struct node
{
    ll l,r;
}a[maxn];

bool cmp(node a,node b)
{
    if(a.l==b.l)
        return a.r>b.r;
    return a.l>b.l;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,p;
        cin>>n>>p;
        for(int i=0;i<n;i++)
        {
            scanf("%lld%lld",&a[i].l,&a[i].r);
            p-=a[i].l;
        }
        sort(a,a+n,cmp);
        ll l=1,r=2e9,mid;
        int cnt=0;
        int id;
        ll pp;
        int flag=0;
        ll zd=1;
        while(l<r)
        {
            mid=(l+r)/2;
            cnt=0;
            id=0;
            pp=p;
            flag=0;
            while(cnt<(n+1)/2&&id<n)
            {
                if(a[id].r>=mid)
                {
                    if(a[id].l<mid)
                        pp-=(mid-a[id].l);
                    cnt++;
                    if(cnt==(n+1)/2)
                    {
                        if(pp>=0)
                        {
                            flag=1;
                            zd=max(zd,mid);
                        }
                    }
                }
                id++;
            }
            if(flag==1)
                l=mid+1;
            else
                r=mid;
        }
        cout<<zd<<endl;
    }
    return 0;
}