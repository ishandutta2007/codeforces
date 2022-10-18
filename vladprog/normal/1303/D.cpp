#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int cnt[60]={};
        while(m--)
        {
            int x;
            cin>>x;
            int k=0;
            while(x>>=1)
                k++;
            cnt[k]++;
        }
        int ans=0,s=0;
        for(int i=0;i<60;i++)
        {
            s+=cnt[i]*(1ll<<i);
            if((n>>i)&1)
                s-=1ll<<i;
            if(s<0)
                ans++;
        }
        if(s<0)
            ans=-1;
        cout<<ans<<"\n";
    }
}