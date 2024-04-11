#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

int calc(int len,int cur)
{
    if(len<cur)
        return 1e18;
    return (cur-len%cur)*(len/cur  )*(len/cur  )+
           (    len%cur)*(len/cur+1)*(len/cur+1);
}

struct cmp
{
    bool operator()(pii a,pii b) const
    {
        return calc(a.x,a.y)-calc(a.x,a.y+1)>calc(b.x,b.y)-calc(b.x,b.y+1);
    }
};

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin>>n>>k;
    k-=n;
    multiset<pii,cmp> s;
    while(n--)
    {
        int a;
        cin>>a;
        s.insert({a,1});
    }
    while(k--)
    {
        auto p=*s.begin();
        s.erase(s.begin());
//        cout<<p.x<<" "<<p.y<<" -> ";
        p.y++;
//        cout<<p.x<<" "<<p.y<<"\n";
        s.insert(p);
    }
    int ans=0;
    for(auto p:s)
        ans+=calc(p.x,p.y);
    cout<<ans;
}