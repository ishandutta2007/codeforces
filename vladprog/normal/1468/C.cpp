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

    int q;
    cin>>q;
    set<pii> num;
    set<pii> val;
    int cnt=0;
    while(q--)
    {
        int tp;
        cin>>tp;
        if(tp==1)
        {
            int m;
            cin>>m;
            m=-m;
            cnt++;
            num.insert({cnt,m});
            val.insert({m,cnt});
        }
        else if(tp==2)
        {
            auto[x,y]=*num.begin();
            num.erase(num.begin());
            val.erase({y,x});
            cout<<x<<" ";
        }
        else
        {
            auto[x,y]=*val.begin();
            val.erase(val.begin());
            num.erase({y,x});
            cout<<y<<" ";
        }
    }
}