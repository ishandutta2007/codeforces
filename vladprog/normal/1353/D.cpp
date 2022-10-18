#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

int a[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            a[i]=0;
        set<pii> s;
        #define add(l,r) s.insert({-((r)-(l)+1),(l)})
        add(1,n);
        for(int i=1;i<=n;i++)
        {
            auto p=*s.begin();
            s.erase(s.begin());
            int l=p.y,r=l-p.x-1;
            int m=(l+r)/2;
//            cout<<p.x<<" "<<p.y<<" -> "<<l<<" "<<r<<" -> "<<m<<"\n";
            a[m]=i;
            add(l,m-1);
            add(m+1,r);
        }
        for(int i=1;i<=n;i++)
            cout<<a[i]<<" ";
        cout<<"\n";
    }
}