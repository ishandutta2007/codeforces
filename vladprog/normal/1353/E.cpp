#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

int solve(string t)
{
    int k0=0,k1=0;
    int best=0,ans=0;
    for(char c:t)
    {
        if(c=='0')
            k0++;
        else
            k1++;
        int val=k0-k1;
        best=max(best,val);
        ans=min(ans,val-best);
    }
    ans+=k1;
    return ans;
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
        int n,k;
        string s;
        cin>>n>>k>>s;
        int total=0;
        for(char c:s)
            total+=c=='1';
        int ans=n;
        for(int i=0;i<k;i++)
        {
            string t;
            for(int j=i;j<n;j+=k)
                t+=s[j];
            int cur=0;
            for(char c:t)
                cur+=c=='1';
            ans=min(ans,solve(t)+total-cur);
        }
        cout<<ans<<"\n";
    }
}