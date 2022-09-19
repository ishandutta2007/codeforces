#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        if(x1!=x2 && y1!=y2)
        cout<<abs(x1-x2)+abs(y1-y2)+2<<endl;
        else
        cout<<abs(x1-x2)+abs(y1-y2)<<endl;
    }
    return 0;
}