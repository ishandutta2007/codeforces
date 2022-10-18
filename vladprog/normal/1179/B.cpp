#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

#define pii pair<int,int>
#define x first
#define y second

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    srand(time(0));

    int n,m;
    cin>>n>>m;
    vector<pii> pos;
    for(int x=1;x<=n;x++)
        for(int y=1;y<=m;y++)
            pos.push_back({x,y});
    for(int i=0,j=n*m-1;i<=j;i++,j--)
    {
        cout<<pos[i].x<<" "<<pos[i].y<<"\n";
        if(i!=j)
            cout<<pos[j].x<<" "<<pos[j].y<<"\n";
    }
}