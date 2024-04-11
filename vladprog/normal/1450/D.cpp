#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=3e5+100;

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
            cnt[i]=0;
        for(int i=1;i<=n;i++)
            cin>>a[i],
            cnt[a[i]]++;
        int l=1,r=n;
        int ans=0;
        while(l<r)
        {
            if(!cnt[ans+1])
                break;
            ans++;
            if(cnt[ans]!=1)
                break;
            if(a[l]==ans)
                l++;
            else if(a[r]==ans)
                r--;
            else
                break;
        }
        ans=min(ans,n-1);
        sort(a+1,a+n+1);
        bool ok=true;
        for(int i=1;i<=n;i++)
            if(a[i]!=i)
                ok=false;
        cout<<ok;
        cout<<string(n-1-ans,'0');
        cout<<string(ans,'1');
        cout<<"\n";
    }
}