#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

int c[N],a[N],b[N];

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
            cin>>c[i];
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
            cin>>b[i];
        for(int i=1;i<=n;i++)
            if(a[i]>b[i])
                swap(a[i],b[i]);
        int ans=0,cur=b[2]-a[2];
        for(int i=2;i<=n;i++)
        {
            cur+=2;
            ans=max(ans,cur+c[i]-1);
            if(a[i+1]==b[i+1])
                cur=0;
            else
                cur+=(c[i]-b[i+1])+(a[i+1]-1);
            cur=max(cur,b[i+1]-a[i+1]);
        }
        cout<<ans<<"\n";
    }
}