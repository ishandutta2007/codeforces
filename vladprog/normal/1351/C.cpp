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
        set<pii> s;
        pii cur(0,0);
        string path;
        cin>>path;
        int ans=0;
        for(char c:path)
        {
            if(c=='S')
                cur.y--;
            if(c=='N')
                cur.y++;
            if(c=='W')
                cur.x--;
            if(c=='E')
                cur.x++;
            if(s.count(cur))
                ans+=1;
            else
                ans+=5;
            s.insert(cur);
            if(c=='S')
                cur.y--;
            if(c=='N')
                cur.y++;
            if(c=='W')
                cur.x--;
            if(c=='E')
                cur.x++;
        }
        cout<<ans<<"\n";
    }
    while(clock()*1.0/CLOCKS_PER_SEC<1);
}