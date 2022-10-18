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
        bool zero=false,one=false;
        int tp=0;
        for(char c:s)
        {
            if(c=='0')
                zero=true;
            else
                one=true;
            if(tp==0&&c=='0'||
               tp==1&&c=='1'||
               tp==2&&c=='0')
                tp++;
        }
        int ans=(!zero?0:!one?1:2);
        if(tp<=2)
            ans=min(ans,1ll);
        cout<<ans<<"\n";
    }
}