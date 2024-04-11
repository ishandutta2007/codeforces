#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

#define maxn 510

int n, m;
string s[maxn];
int v[maxn][maxn];
int o[maxn][maxn];

int main()
{
    cin>>n>>m;

    for(int i=0; i<n; ++i)
        cin>>s[i];

    for(int i=0; i<n; ++i)
        for(int j=0; j<m-1; ++j)
            if(s[i][j]=='.' && s[i][j+1]=='.')
                ++o[i+1][j+1];

     for(int i=0; i<n-1; ++i)
        for(int j=0; j<m; ++j)
            if(s[i][j]=='.' && s[i+1][j]=='.')
                ++v[i+1][j+1];

    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
        {
            v[i][j]+=v[i-1][j];
            o[i][j]+=o[i-1][j];
        }

    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
        {
            v[i][j]+=v[i][j-1];
            o[i][j]+=o[i][j-1];
        }

    int q, x1, x2, y1, y2;

    cin>>q;
    while(q--)
    {
        cin>>x1>>y1>>x2>>y2;

        cout<<o[x2][y2-1]+o[x1-1][y1-1]-o[x2][y1-1]-o[x1-1][y2-1]+v[x2-1][y2]+v[x1-1][y1-1]-v[x2-1][y1-1]-v[x1-1][y2]<<"\n";
    }

    return 0;
}