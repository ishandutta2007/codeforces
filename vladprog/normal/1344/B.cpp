#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1010;

int n,m;
string s[N];
int l[N],r[N],u[N],d[N];

bool black(int i,int j)
{
    return 0<=i&&i<n&&0<=j&&j<m&&s[i][j]=='#';
}

void dfs(int i,int j)
{
    if(!black(i,j))
        return;
    s[i][j]='.';
    dfs(i+1,j);
    dfs(i,j+1);
    dfs(i,j-1);
    dfs(i-1,j);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>s[i];
    for(int i=0;i<n;i++)
        l[i]=m,r[i]=-1;
    for(int j=0;j<m;j++)
        u[j]=n,d[j]=-1;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(s[i][j]=='#')
                l[i]=min(l[i],j),
                r[i]=max(r[i],j),
                u[j]=min(u[j],i),
                d[j]=max(d[j],i);
    bool row=false,col=false;
    for(int i=0;i<n;i++)
        if(r[i]==-1)
            row=true;
    for(int j=0;j<m;j++)
        if(d[j]==-1)
            col=true;
    if(row!=col)
        cout<<-1,
        exit(0);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(s[i][j]=='.'&&
               ((l[i]<=j&&j<=r[i])||
                (u[j]<=i&&i<=d[j])))
                cout<<-1,
                exit(0);
    int ans=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(s[i][j]=='#')
                dfs(i,j),
                ans++;
    cout<<ans;
}