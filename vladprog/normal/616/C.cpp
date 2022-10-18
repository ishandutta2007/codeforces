#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef pair<pii,int> ppi;

const int N=1e3+5;

string a[N];
pii p[N][N];
int sz[N][N];
set<ppi> s;

pii finds(int x,int y)
{
    if(p[x][y]==pii{x,y})
        return {x,y};
    else
        return p[x][y]=
               finds(p[x][y].first,p[x][y].second);
}

void unions(int x1,int y1,int x2,int y2)
{
    pii p1=finds(x1,y1);
    x1=p1.first;
    y1=p1.second;
    pii p2=finds(x2,y2);
    x2=p2.first;
    y2=p2.second;
    if(pii{x1,y1}==pii{x2,y2})
        return;
    if(sz[x1][y1]<sz[x2][y2])
        swap(x1,x2),
        swap(y1,y2),
        swap(p1,p2);
    sz[x1][y1]+=sz[x2][y2];
    p[x2][y2]={x1,y1};
}

void add(int x,int y)
{
    if(a[x][y]!='.')
        return;
    pii p1=finds(x,y);
    int x1=p1.first,y1=p1.second;
    s.insert({p1,sz[x1][y1]});
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    a[0]=string(m+2,'*');
    a[n+1]=string(m+2,'*');
    for(int i=1;i<=n;i++)
        cin>>a[i],a[i]='*'+a[i]+'*';
    for(int i=0;i<n+2;i++)
        for(int j=0;j<m+2;j++)
            sz[i][j]=1,p[i][j]={i,j};
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m-1;j++)
            if(a[i][j]=='.'&&
               a[i][j+1]=='.')
                unions(i,j,i,j+1);
    for(int i=1;i<=n-1;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j]=='.'&&
               a[i+1][j]=='.')
                unions(i,j,i+1,j);

//    for(int x=0;x<=n+1;x++)
//    {
//        for(int y=0;y<=m+1;y++)
//        {
//            if(a[x][y]=='*')
//            {
//                cout<<"* ";
//                continue;
//            }
//            pii p1=finds(x,y);
//            int x1=p1.first,y1=p1.second;
//            //cout<<sz[x1][y1]<<" ";
//            cout<<"("<<x1<<","<<y1<<") ";
//        }
//        cout<<endl;
//    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]!='*')
            {
                //cout<<". ";
                continue;
            }
            s.clear();
            add(i,j+1);
            add(i,j-1);
            add(i+1,j);
            add(i-1,j);
            int res=1;
            //cout<<s.size()<<" ";
//            cout<<i<<","<<j<<"->";
            for(ppi t:s)
                res+=t.second;
//                cout<<"("<<t.first.first<<","
//                         <<t.first.second<<") ";
//            cout<<endl;
            a[i][j]=res%10+'0';
        }
        //cout<<endl;
    }
    for(int i=1;i<=n;i++)
        cout<<a[i].substr(1,m)<<"\n";
}