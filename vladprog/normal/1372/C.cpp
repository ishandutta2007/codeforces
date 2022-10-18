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
            cin>>a[i];
        int l=n+1,r=0;
        for(int i=1;i<=n;i++)
            if(a[i]!=i)
                l=min(l,i),
                r=max(r,i);
        if(!r)
        {
            cout<<0<<"\n";
            continue;
        }
        bool eq=false;
        for(int i=l;i<=r;i++)
            if(a[i]==i)
                eq=true;
        cout<<(!eq?1:2)<<"\n";
    }
}