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
        bool l=true,r=true;
        for(char c:s)
            if(c=='<')
                r=false;
            else if(c=='>')
                l=false;
        if(l||r)
        {
            cout<<n<<"\n";
            continue;
        }
        int ans=0;
        for(int i=0;i<n;i++)
            if(s[i]=='-'||s[(i+1)%n]=='-')
                ans++;
        cout<<ans<<"\n";
    }
}