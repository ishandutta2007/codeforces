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
        string s;
        cin>>s;
        int round=0,square=0;
        int ans=0;
        for(char c:s)
            if(c=='(')
               round++;
            else if(c==')'&&round)
                round--,ans++;
            else if(c=='[')
                square++;
            else if(c==']'&&square)
                square--,
                ans++;
        cout<<ans<<"\n";
    }
}