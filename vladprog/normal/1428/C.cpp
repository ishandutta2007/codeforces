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
        reverse(s.begin(),s.end());
        int ans=s.size(),cnt=0;
        for(char c:s)
            if(c=='B')
                cnt++;
            else if(cnt)
                cnt--,ans-=2;
        cout<<ans-cnt/2*2<<"\n";
    }
}