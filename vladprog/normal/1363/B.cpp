#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1010;

int pref0[N],pref1[N],suff0[N],suff1[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n=s.size();
        s="_"+s;
        pref0[0]=pref1[0]=0;
        for(int i=1;i<=n;i++)
            pref0[i]=pref0[i-1]+(s[i]=='0'),
            pref1[i]=pref1[i-1]+(s[i]=='1');
        suff0[n+1]=suff1[n+1]=0;
        for(int i=n;i>=1;i--)
            suff0[i]=suff0[i+1]+(s[i]=='0'),
            suff1[i]=suff1[i+1]+(s[i]=='1');
        int ans=1e9;
        for(int i=0;i<=n;i++)
            ans=min(ans,pref0[i]+suff1[i+1]),
            ans=min(ans,pref1[i]+suff0[i+1]);
        cout<<ans<<"\n";
    }
}