#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,r;
        cin>>a>>b>>c>>r;
        if(a>b)
            swap(a,b);
        int x=c-r,y=c+r;
        int all=b-a;
        int no=max(0ll,min(b,y)-max(a,x));
        cout<<all-no<<"\n";
    }
}