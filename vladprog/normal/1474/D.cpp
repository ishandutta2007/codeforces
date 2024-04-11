#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

int a[N],pref[N],suff[N];

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
        pref[0]=0;
        for(int i=1;i<=n;i++)
            if(pref[i-1]<0)
                pref[i]=-1;
            else
                pref[i]=a[i]-pref[i-1];
        suff[n+1]=0;
        for(int i=n;i>=1;i--)
            if(suff[i+1]<0)
                suff[i]=-1;
            else
                suff[i]=a[i]-suff[i+1];
        bool yes=pref[n]==0;
        for(int i=1;i<=n-1;i++)
            if(pref[i-1]>=0&&suff[i+2]>=0&&
               a[i+1]-pref[i-1]>=0&&
               a[i]-a[i+1]+pref[i-1]>=0&&
               suff[i+2]-a[i]+a[i+1]-pref[i-1]==0)
                yes=true;
        cout<<(yes?"YES\n":"NO\n");
    }
}