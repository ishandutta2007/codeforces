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
        int x,y,a,b;
        cin>>x>>y>>a>>b;
        b=min(b,2*a);
        int q=0;
        if(x>0&&y>0)
            q=min(x,y),
            x-=q,y-=q;
        if(x<0&&y<0)
            q=min(-x,-y),
            x+=q,y+=q;
        int p=abs(x)+abs(y);
        cout<<a*p+b*q<<"\n";
    }
}