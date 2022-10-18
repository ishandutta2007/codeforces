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
        map<pii,int> m;
        m[{0,0}]=-1;
        int x=0,y=0;
        int ans=1e9,l=0,r;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='L')
                x--;
            if(s[i]=='R')
                x++;
            if(s[i]=='U')
                y++;
            if(s[i]=='D')
                y--;
            if(m.count({x,y}))
            {
                int p=m[{x,y}];
                if(i-p<ans)
                    ans=i-p,
                    l=p+1+1,r=i+1;
            }
            m[{x,y}]=i;
        }
        if(l)
            cout<<l<<" "<<r<<"\n";
        else
            cout<<-1<<"\n";
    }
}