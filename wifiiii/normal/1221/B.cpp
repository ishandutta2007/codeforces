
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

int a[105][105];
int dir1[] = {-1,-1,-2,-2,1,1,2,2};
int dir2[] = {2,-2,1,-1,2,-2,1,-1};
int main()
{
    int n;
    cin>>n;
    a[1][1] = 1;
    queue<pair<int,int>> q;
    q.push({1,1});
    while(!q.empty())
    {
        auto p = q.front();q.pop();
        for(int i=0;i<8;++i)
        {
            int xx = p.first + dir1[i], yy = p.second + dir2[i];
            if(xx<=0 || yy<=0 || xx>n || yy>n || a[xx][yy]) continue;
            a[xx][yy] = 3 - a[p.first][p.second];
            q.push({xx,yy});
        }
    }
    ii {ji if(a[i][j]==1) cout<<"W";else cout<<"B";cout<<endl;}
}