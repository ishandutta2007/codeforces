#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

const int N=2e5+100;

int b[N];

int prime(int x)
{
    if(x==1)
        return 0;
    for(int i=2;i*i<=x;i++)
        if(x%i==0)
            return 2;
    return 1;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,e;
        cin>>n>>e;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin>>a;
            b[i]=prime(a);
        }
        int ans=0;
        for(int i=1;i<=e;i++)
        {
            int l=0,r=0;
            for(int j=i;j<=n;j+=e)
            {
                if(b[j]==2)
                    l=r=0;
                else if(b[j]==1)
                    l=r+1,r=0;
                else
                    l++,r++;
//                cout<<l<<" "<<r<<endl;
                ans+=l-r;
                if(b[j]==1)
                    ans--;
            }
        }
        cout<<ans<<"\n";
    }
}