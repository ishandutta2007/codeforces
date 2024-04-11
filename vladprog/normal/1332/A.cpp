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
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int x,y,x1,y1,x2,y2;
        cin>>x>>y>>x1>>y1>>x2>>y2;
        x1-=x,x2-=x;
        y1-=y,y2-=y;
        x=b-a,y=d-c;
        if(!(x1<=x&&x<=x2&&
             y1<=y&&y<=y2))
        {
            cout<<"No\n";
            continue;
        }
        if(a+b&&!x1&&!x2)
        {
            cout<<"No\n";
            continue;
        }
        if(c+d&&!y1&&!y2)
        {
            cout<<"No\n";
            continue;
        }
        cout<<"Yes\n";
    }
}