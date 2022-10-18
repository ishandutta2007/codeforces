#include<bits/stdc++.h>

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
        int k=n/2;
        int ans=n;
        for(int x=0;x<=k;x++)
            for(int y=0;y<=k;y++)
            {
                int d=x,op=k-x,cl=k-y;
                for(char c:s)
                    if(c=='('&&op)
                        d++,
                        op--;
                    else if(c==')'&&cl&&d)
                        d--,
                        cl--;
                if(!op&&!cl)
                    ans=min(ans,x+y);
            }
        cout<<ans<<"\n";
    }
}