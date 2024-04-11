#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

int solve(int len,int x,int y)
{
    return min(len*x,len/2*y+len%2*x);
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
        int n,m,x,y;
        cin>>n>>m>>x>>y;
        int ans=0;
        while(n--)
        {
            string s;
            cin>>s;
            int len=0;
            for(char c:s)
                if(c=='*')
                    len=0;
                else
                    ans-=solve(len,x,y),
                    len++,
                    ans+=solve(len,x,y);
        }
        cout<<ans<<"\n";
    }
}