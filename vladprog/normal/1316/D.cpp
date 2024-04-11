#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1010;

int x[N][N],y[N][N];
string s[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>x[i][j]>>y[i][j];
    for(int i=1;i<=n;i++)
        s[i]="_"+string(n,'?');
    queue<pii> q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(x[i][j]==i&&y[i][j]==j)
                s[i][j]='X',
                q.push({i,j});
            else if(x[i][j]==-1)
                if(x[i-1][j]==-1) s[i][j]='U';
                else if(x[i+1][j]==-1) s[i][j]='D';
                else if(x[i][j-1]==-1) s[i][j]='L';
                else if(x[i][j+1]==-1) s[i][j]='R';
                else cout<<"INVALID",exit(0);
    while(!q.empty())
    {
        int i=q.front().x,j=q.front().y;
        q.pop();
        #define relax(r,c,ch) if(x[r][c]==x[i][j]&&y[r][c]==y[i][j]&&s[r][c]=='?') s[r][c]=ch,q.push({r,c})
        relax(i-1,j,'D');
        relax(i+1,j,'U');
        relax(i,j-1,'R');
        relax(i,j+1,'L');
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(s[i][j]=='?')
                cout<<"INVALID",exit(0);
    cout<<"VALID\n";
    for(int i=1;i<=n;i++)
        cout<<s[i].substr(1)<<"\n";
}