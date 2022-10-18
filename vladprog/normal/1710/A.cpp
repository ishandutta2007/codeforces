#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int x=0,y=0;
        bool X=false,Y=false;
        while(k--)
        {
            int a;
            cin>>a;
            if(a/n>=2)
                x+=a/n;
            if(a/m>=2)
                y+=a/m;
            if(a/n>=3)
                X=true;
            if(a/m>=3)
                Y=true;
        }
        cout<<(x>=m&&(X||m%2==0)||
               y>=n&&(Y||n%2==0)?"Yes\n":"No\n");
    }
}