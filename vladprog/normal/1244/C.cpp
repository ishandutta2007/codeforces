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

    int n,p,w,d;
    cin>>n>>p>>w>>d;
    for(int x=0;x<d;x++)
    {
        int yd=p-x*w;
        if(yd%d)
            continue;
        int y=yd/d;
        int z=n-x-y;
        if(y<0||z<0)
            continue;
        cout<<x<<" "<<y<<" "<<z<<"\n";
        return 0;
    }
    for(int y=0;y<w;y++)
    {
        int xw=p-y*d;
        if(xw%w)
            continue;
        int x=xw/w;
        int z=n-x-y;
        if(x<0||z<0)
            continue;
        cout<<x<<" "<<y<<" "<<z<<"\n";
        return 0;
    }
    cout<<-1<<"\n";
}