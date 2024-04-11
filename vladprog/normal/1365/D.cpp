#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=55;

string s[N];
bool ok;

void dfs(int x,int y)
{
    if(s[x][y]=='#'||s[x][y]=='V')
        return;
    if(s[x][y]=='B')
        ok=false;
    s[x][y]='V';
    dfs(x-1,y);
    dfs(x+1,y);
    dfs(x,y-1);
    dfs(x,y+1);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            cin>>s[i],
            s[i]='#'+s[i]+'#';
        s[0]=s[n+1]=string(m+2,'#');
        ok=true;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(s[i][j]=='B')
                {
                    #define add(x,y) \
                        if(s[x][y]=='G') \
                            ok=false; \
                        else if(s[x][y]=='.') \
                            s[x][y]='#'
                    add(i-1,j);
                    add(i+1,j);
                    add(i,j-1);
                    add(i,j+1);
                }
        dfs(n,m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(s[i][j]=='G')
                    ok=false;
        cout<<(ok?"Yes\n":"No\n");
    }
}