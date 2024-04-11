#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
random_device rng;
mt19937 mrand(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'
 
// dir = {U, D, L, R, UL, UR, DL, DR}
int cnt[9];
pair<int,int> a[200005];
const int inf = 1e9;
int main()
{
    int n,x,y;
    cin>>n>>x>>y;
    for(int i=1;i<=n;++i) cin>>a[i].first>>a[i].second;
    int mx=-1;
    int ax=0,ay=0;
    int tx=x-1,ty=y;
    if(tx>=0&&ty>=0&&tx<=inf&&ty<=inf)
    {
        int cnt = 0;
        for(int i=1;i<=n;++i)
        {
            if(a[i].first < x) cnt++;
        }
        if(cnt > mx)
        {
            mx = cnt;
            ax=tx,ay=ty;
        }
    }
    tx=x+1,ty=y;
    if(tx>=0&&ty>=0&&tx<=inf&&ty<=inf)
    {
        int cnt = 0;
        for(int i=1;i<=n;++i)
        {
            if(a[i].first > x) cnt++;
        }
        if(cnt > mx)
        {
            mx = cnt;
            ax=tx,ay=ty;
        }
    }
    tx=x,ty=y-1;
    if(tx>=0&&ty>=0&&tx<=inf&&ty<=inf)
    {
        int cnt = 0;
        for(int i=1;i<=n;++i)
        {
            if(a[i].second < y) cnt++;
        }
        if(cnt > mx)
        {
            mx = cnt;
            ax=tx,ay=ty;
        }
    }
    tx=x,ty=y+1;
    if(tx>=0&&ty>=0&&tx<=inf&&ty<=inf)
    {
        int cnt = 0;
        for(int i=1;i<=n;++i)
        {
            if(a[i].second > y) cnt++;
        }
        if(cnt > mx)
        {
            mx = cnt;
            ax=tx,ay=ty;
        }
    }
    cout << mx << endl;
    cout << ax << " " << ay << endl;
}