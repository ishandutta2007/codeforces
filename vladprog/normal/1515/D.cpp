#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

int a[N],b[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,l,r;
        cin>>n>>l>>r;
        for(int i=1;i<=n;i++)
            a[i]=b[i]=0;
        for(int i=1;i<=l;i++)
        {
            int c;
            cin>>c;
            a[c]++;
        }
        for(int i=1;i<=r;i++)
        {
            int c;
            cin>>c;
            b[c]++;
        }
        int l1=0,l2=0,r1=0,r2=0;
        for(int i=1;i<=n;i++)
        {
            int m=min(a[i],b[i]);
            a[i]-=m;
            b[i]-=m;
            l1+=a[i]%2;
            l2+=a[i]/2*2;
            r1+=b[i]%2;
            r2+=b[i]/2*2;
        }
        int ans=0,m;

        m=min(l1,r1);
        l1-=m;
        r1-=m;
        ans+=m;

        m=min(l1,r2);
        l1-=m;
        r2-=m;
        ans+=m;

        m=min(l2,r1);
        l2-=m;
        r1-=m;
        ans+=m;

        m=l2;
        l2-=m;
        ans+=m/2;

        m=r2;
        r2-=m;
        ans+=m/2;

        ans+=l1+l2+r1+r2;

        cout<<ans<<"\n";
    }
}