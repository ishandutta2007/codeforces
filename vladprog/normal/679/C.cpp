#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=510;

string s[N];
int pref[N][N];
int comp[N][N];
int sz[N*N];
int xl[N*N],xr[N*N],yl[N*N],yr[N*N];
bool in[N*N];
bool brd[N*N];

void dfs(int x,int y,int c)
{
    if(comp[x][y]||s[x][y]=='X')
        return;
    comp[x][y]=c;
    sz[c]++;
    xl[c]=min(xl[c],x);
    xr[c]=max(xr[c],x);
    yl[c]=min(yl[c],y);
    yr[c]=max(yr[c],y);
    dfs(x+1,y,c);
    dfs(x-1,y,c);
    dfs(x,y+1,c);
    dfs(x,y-1,c);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>s[i],
        s[i]="X"+s[i]+"X";
    s[0]=s[n+1]=string(n+2,'X');
    int cnt=0;
    for(int x=1;x<=n;x++)
        for(int y=1;y<=n;y++)
        {
            if(s[x][y]=='X')
                pref[x][y]=1;
            pref[x][y]+=pref[x-1][y]+pref[x][y-1]-pref[x-1][y-1];
            if(s[x][y]=='.')
            {
                cnt++;
                xl[cnt]=yl[cnt]=1e9;
                xr[cnt]=yr[cnt]=-1e9;
                dfs(x,y,cnt);
            }
        }
//    for(int i=0;i<=n+1;i++,cout<<"\n")
//        for(int j=0;j<=n+1;j++)
//            cout<<comp[i][j];
    int ans=0;
    for(int x=1;x+k-1<=n;x++)
    {
        int in_sum=0;
        for(int c=1;c<=cnt;c++)
            if(x<=xl[c]&&xr[c]<=x+k-1&&
               1<=yl[c]&&yr[c]<=1+k-1)
                in[c]=true,
                in_sum+=sz[c];
            else
                in[c]=false;
        int y=0;
        while(y<=n-1)
        {
            #define check \
            { \
                bool need=(x<=xl[c]&&xr[c]<=x+k-1&& \
                           y<=yl[c]&&yr[c]<=y+k-1); \
                bool now=in[c]; \
                if(need&&!now) \
                    in[c]=true, \
                    in_sum+=sz[c]; \
                if(!need&&now) \
                    in[c]=false, \
                    in_sum-=sz[c]; \
            }
            if(y)
                for(int i=x;i<=x+k-1;i++)
                {
                    int c=comp[i][y+k-1+1];
                    y++;
                    check
                    y--;
                }
            y++;
            for(int i=x;i<=x+k-1;i++)
            {
                int c=comp[i][y-1];
                check
            }
            #define add(c) if(!brd[c]) /*cout<<c<<" ",*/res+=sz[c],brd[c]=true
            int res=in_sum+pref[x+k-1][y+k-1]-pref[x-1][y+k-1]-pref[x+k-1][y-1]+pref[x-1][y-1];
//            cout<<x<<" "<<y<<" -> "<<res<<" | ";
            for(int i=x;i<=x+k-1;i++)
            {
                add(comp[i][y-1]);
                add(comp[i][y+k-1+1]);
            }
            for(int j=y;j<=y+k-1;j++)
            {
                add(comp[x-1][j]);
                add(comp[x+k-1+1][j]);
            }
//            cout<<" -> "<<res<<"\n";
            ans=max(ans,res);
            #define del(c) brd[c]=false
            for(int i=x;i<=x+k-1;i++)
            {
                del(comp[i][y-1]);
                del(comp[i][y+k-1+1]);
            }
            for(int j=y;j<=y+k-1;j++)
            {
                del(comp[x-1][j]);
                del(comp[x+k-1+1][j]);
            }
        }
    }
    cout<<ans;
}