#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

int a[N];
int cnt[N];

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
        for(int i=1;i<=n;i++)
            cnt[i]=0;
        int ans=0;
        for(int i=1;i<=n-1;i++)
            if(a[i]==a[i+1])
                cnt[a[i]]++,
                cnt[a[i+1]]++,
                ans++;
        cnt[a[1]]++;
        cnt[a[n]]++;
        pii mx(-1,-1);
        int sum=0;
        for(int i=1;i<=n;i++)
            mx=max(mx,pii(cnt[i],i)),
            sum+=cnt[i];
        for(int i=1;i<=n-1&&mx.x*2>sum+2;i++)
            if(a[i]!=a[i+1]&&
               a[i]!=mx.y&&
               a[i+1]!=mx.y)
                sum+=2,
                ans++;
        if(mx.x*2>sum+2)
            cout<<-1<<"\n";
        else
            cout<<ans<<"\n";
    }
}