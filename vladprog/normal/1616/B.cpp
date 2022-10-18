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
        string ans;
        for(char c:s)
            if(ans.empty()||ans.back()>c||
               ans.front()!=ans.back()&&ans.back()==c)
                ans+=c;
            else
                break;
        cout<<ans;
        reverse(ans.begin(),ans.end());
        cout<<ans<<"\n";
    }
}