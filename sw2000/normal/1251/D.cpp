#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const int inf=0x3f3f3f3f;

struct R
{
    ll l,r;
    friend bool operator<(const R &a,const R &b)
    {
        return a.r>b.r;
    }

}r[maxn];

bool cmp(R a,R b)
{
    return a.l<b.l;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        priority_queue<R>q;
        ll n,s;
        scanf("%lld%lld",&n,&s);
        ll mid=n/2;
        for(int i=0;i<n;i++)
        {
            scanf("%lld%lld",&r[i].l,&r[i].r);
            s-=r[i].l;
        }
        sort(r,r+n,cmp);
        for(int i=mid;i<n;i++)
        {
            q.push(r[i]);
        }

        ll ans=r[mid].l,cnt=1,mi=mid;
        while(s)
        {
            if(cnt!=n/2+1&&q.top().r>=r[mid+cnt].l)
            {
                if(s>cnt*(r[mid+cnt].l-ans))
                {
                    s-=cnt*(r[mid+cnt].l-ans);
                    ans=r[mid+cnt].l;
                    cnt++;
                }
                else
                {
                    ans+=s/cnt;
                    s=0;
                }
            }
            else
            {
                R x=q.top();q.pop();
                if(s>cnt*(x.r-ans))
                {
                    s-=cnt*(x.r-ans);
                    ans=x.r;
                }
                else
                {
                    ans+=s/cnt;
                    break;
                }

                if(mi==0)break;
                mi--;
                while(r[mi].r<=x.r)
                {
                    mi--;
                    if(mi==-1)break;
                }
                if(mi==-1)break;

                q.push(r[mi]);
                if(s>x.l-r[mi].l)
                {
                    s-=x.l-r[mi].l;
                }
                else s=0;
            }
        }

        printf("%lld\n",ans);
    }
    return 0;
}