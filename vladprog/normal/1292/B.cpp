#include<bits/stdc++.h>

typedef long long ll;
#define int ll
typedef long double ld;

using namespace std;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

bool bad[3][N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x0,y0,ax,ay,bx,by,xs,ys,t;
    cin>>x0>>y0>>ax>>ay>>bx>>by>>xs>>ys>>t;
    vector<pair<int,int>> v;
    while(x0<=2.1e16&&y0<=2.1e16)
        v.emplace_back(x0,y0),
        x0=ax*x0+bx,
        y0=ay*y0+by;

    int ans=0;
    for(int l=0;l<v.size();l++)
        for(int r=l;r<v.size();r++)
        {
            int sl=abs(xs-v[l].x)+abs(ys-v[l].y);
            int sr=abs(xs-v[r].x)+abs(ys-v[r].y);
            int lr=abs(v[r].x-v[l].x)+abs(v[r].y-v[l].y);
            int slr=sl+lr;
            int srl=sr+lr;
            int dist=min(slr,srl);
            if(dist<=t)
                ans=max(ans,r-l+1);
        }
    cout<<ans;
}