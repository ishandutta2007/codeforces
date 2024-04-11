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

    int h,w;
    cin>>h>>w;
    char c[h][w];
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
            cin>>c[i][j];
    int x=0,y=0,ans=c[0][0]=='*';
    while(x<h-1&&y<w-1)
    {
        int i=x+1;
        while(i<h&&c[i][y]=='.')
            i++;
        if(i==h)
            i=10;
        else
            i-=x;
        int j=y+1;
        while(j<w&&c[x][j]=='.')
            j++;
        if(j==w)
            j=10;
        else
            j-=y;
        if(j<=i)
            y++;
        else
            x++;
        if(c[x][y]=='*')
            ans++;
    }
    while(x<h-1)
    {
        x++;
        if(c[x][y]=='*')
            ans++;
    }
    while(y<w-1)
    {
        y++;
        if(c[x][y]=='*')
            ans++;
    }
    cout<<ans;
}