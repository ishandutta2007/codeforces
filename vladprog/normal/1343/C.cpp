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
        cin>>n;
        pii pos(0,0),neg(0,0);
        while(n--)
        {
            int a;
            cin>>a;
            pii upd=(a>0?neg:pos);
            upd.x++;
            upd.y+=a;
            if(a>0)
                pos=max(pos,upd);
            else
                neg=max(neg,upd);
        }
        pii ans=max(pos,neg);
        cout<<ans.y<<"\n";
    }
}