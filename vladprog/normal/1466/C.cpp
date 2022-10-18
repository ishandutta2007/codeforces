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
        s="12"+s;
        int ans=0;
        for(int i=2;i<s.size();i++)
            if(s[i]==s[i-1]||s[i]==s[i-2])
                s[i]='.',
                ans++;
        cout<<ans<<"\n";
    }
}