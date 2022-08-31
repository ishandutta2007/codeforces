#include <iostream>
#define N 105
using namespace std;
int scol[N];
int srow[N];
int kcol[N];
int krow[N];
int tab[N][N];
bool zle(int n, int m)
{
    for(int i=1; i<=n; i++)
    {
        if(srow[i]<0)
        return 1;
    }
    for(int i=1; i<=m; i++)
    {
        if(scol[i]<0)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    int n, m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>tab[i][j];
            srow[i]+=tab[i][j];
            scol[j]+=tab[i][j];
        }
    }
    while(zle(n, m))
    {
        for(int i=1; i<=n; i++)
        {
            if(srow[i]<0)
            {
                krow[i]=(1^krow[i]);
                for(int j=1; j<=m; j++)
                {
                    scol[j]-=2*tab[i][j];
                    tab[i][j]*=-1;
                }
                srow[i]*=-1;
            }
        }
        for(int i=1; i<=m; i++)
        {
            if(scol[i]<0)
            {
                kcol[i]=(1^kcol[i]);
                for(int j=1; j<=n; j++)
                {
                    srow[j]-=2*tab[j][i];
                    tab[j][i]*=-1;
                }
                scol[i]*=-1;
            }
        }
    }
    int a=0, b=0;
    for(int i=1; i<=n; i++)
    {
        a+=krow[i];
    }
    for(int i=1; i<=m; i++)
    {
        b+=kcol[i];
    }
    cout<<a<<" ";
    for(int i=1; i<=n; i++)
    {
        if(krow[i]==1)
        {
            cout<<i<<" ";
        }
    }
    cout<<endl<<b<<" ";
    for(int i=1; i<=m; i++)
    {
        if(kcol[i]==1)
        {
            cout<<i<<" ";
        }
    }
    cout<<endl;
    return 0;
}