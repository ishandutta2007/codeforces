#include<bits/stdc++.h>

typedef long long ll;
#define int ll
typedef long double ld;

using namespace std;

const int N=1e5+100;

bool bad[3][N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,q;
    cin>>n>>q;
    int cnt=0;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        int x1=3-x;
        if(bad[x][y])
        {
            for(int y1=y-1;y1<=y+1;y1++)
                if(bad[x1][y1])
                    cnt--;
            bad[x][y]=false;
        }
        else
        {
            for(int y1=y-1;y1<=y+1;y1++)
                if(bad[x1][y1])
                    cnt++;
            bad[x][y]=true;
        }
        cout<<(cnt?"No\n":"Yes\n");
    }
}