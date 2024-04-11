#include <bits/stdc++.h>

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
        int n;
        string s;
        cin>>n>>s;
        string q=s;
        sort(q.begin(),q.end());
        int ans=0;
        for(int i=0;i<n;i++)
            if(s[i]!=q[i])
                ans++;
        cout<<ans<<"\n";
    }
}