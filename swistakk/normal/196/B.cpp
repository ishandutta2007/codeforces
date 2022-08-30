#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <utility>
#define N 1555
using namespace std;
int ruchx[5]={0, 1, 0, -1};
int ruchy[5]={1, 0, -1, 0};
int pla[N][N];
int n, m;
int czy(int a, int b)
{
    return pla[(a%n+n)%n][(b%m+m)%m]==1;
}
pair<int, int> vis[N][N];
// map< pair<int, int>, bool > mapka;
vector< pair<int, int> > kol;
int main()
{
    ios_base::sync_with_stdio(0);
    // int n, m;
    cin>>n>>m;
    char c;
    int sx, sy;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            vis[i][j]=make_pair(-N*N, -N*N);
            cin>>c;
            if(c=='.')
            {
                pla[i][j]=1;
            }
            if(c=='S')
            {
                sx=j;
                sy=i;
                pla[i][j]=1;
            }
        }
    }
    kol.push_back( make_pair(sx, sy) );
    for(int i=0; i<kol.size() && kol.size()<n*m+5; i++)
    {
        int aktx=kol[i].first;
        int akty=kol[i].second;
        for(int j=0; j<4; j++)
        {
            int zx=aktx+ruchx[j];
            int zy=akty+ruchy[j];
            if( czy(akty+ruchy[j], aktx+ruchx[j]) && vis[(zy+N*n)%n][(zx+N*m)%m]!= make_pair( zy, zx ) )
            {
                kol.push_back( make_pair(aktx+ruchx[j], akty+ruchy[j]) );
                if( vis[(zy+N*n)%n][(zx+N*m)%m]!= make_pair(-N*N, -N*N))
                {
                    cout<<"Yes"<<endl;
                    return 0;
                }
                vis[(zy+N*n)%n][(zx+N*m)%m]=make_pair(zy, zx);
                // mapka[ make_pair(aktx+ruchx[j], akty+ruchy[j]) ]=1;
            }
        }
    }
    //<<kol.size()<<endl;
    /* if(kol.size()>n*m)
    {
        cout<<"Yes"<<endl;
    }
    else
    { */
        cout<<"No"<<endl;
    // }
    
    
    return 0;
}