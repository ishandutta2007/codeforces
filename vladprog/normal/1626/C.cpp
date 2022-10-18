#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=110;

int k[N],h[N];

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
            cin>>k[i];
        for(int i=1;i<=n;i++)
            cin>>h[i];
        for(int i=n;i>=2;i--)
            h[i-1]=max(h[i-1],h[i]-k[i]+k[i-1]);
        for(int i=2;i<=n;i++)
            if(h[i]-k[i]+k[i-1]>=1)
                h[i]=h[i-1]-k[i-1]+k[i];
        int ans=0;
        for(int i=n;i>=1;i--)
        {
            int K=k[i]-h[i]+1;
            int H=1;
            if(K<=k[i-1])
                K=k[i-1]+1,
                H=h[i]-k[i]+K;
            ans+=(H+h[i])*(h[i]-H+1)/2;
        }
        cout<<ans<<"\n";
    }
}