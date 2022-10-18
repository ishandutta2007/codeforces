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
        int x,y,c[7];
        cin>>x>>y;
//        x=rand(),y=rand();
        for(int i=1;i<=6;i++)
            cin>>c[i];
        for(int i=1;i<=6;i++)
            for(int j=1;j<=6;j++)
                c[j]=min(c[j],c[j%6+1]+c[(j+4)%6+1]);
        int ans=0;
        if(x>0)
        {
            int a=min(x,max(0ll,y)),b=x-a;
            assert(b>=0);
            ans+=c[1]*a+c[6]*b;
            x-=a+b;
            y-=a;
//            cerr<<"> "<<a<<" "<<b<<" -> "<<x<<" "<<y<<"\n";
        }
        if(x<0)
        {
            int a=min(-x,max(0ll,-y)),b=-x-a;
            assert(b>=0);
            ans+=c[4]*a+c[3]*b;
            x+=a+b;
            y+=a;
//            cerr<<"< "<<a<<" "<<b<<" -> "<<x<<" "<<y<<"\n";
        }
        assert(x==0);
        if(y>0)
            ans+=c[2]*y;
        else
            ans+=c[5]*(-y);
        cout<<ans<<"\n";
    }
}