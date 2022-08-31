#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#define N 20004
#define D 100000005
using namespace std;
char s[105][N];
int w[105][N];
int main()
{
    ios_base::sync_with_stdio(0);
    int n, m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        int sum=0;
        for(int j=1; j<=m; j++)
        {
            cin>>s[i][j];
            if(s[i][j]=='1')
            {
                sum++;
            }
            s[i][j+m]=s[i][j];
            w[i][j]=D;
            w[i][j+m]=D;
        }
        if(sum==0)
        {
            cout<<"-1"<<endl;
            return 0;
        }
    }
    int akt=D;
    for(int i=1; i<=n; i++)
    {
        akt=D;
        for(int j=1; j<=2*m; j++)
        {
            if(s[i][j]=='1')
            {
                akt=0;
            }
            else
            {
                akt++;
            }
            w[i][j]=min(w[i][j], akt);
        }
        akt=D;
        for(int j=2*m; j>=1; j--)
        {
            if(s[i][j]=='1')
            {
                akt=0;
            }
            else
            {
                akt++;
            }
            w[i][j]=min(w[i][j], akt);
        }
    }
    int wynik=D;
    int aktw=0;
    for(int i=1; i<=m; i++)
    {
        aktw=0;
        for(int j=1; j<=n; j++)
        {
            aktw+=min(w[j][i], w[j][i+m]);
        }
        wynik=min(wynik, aktw);
    }
        
    if(wynik>=n*m)
    {
        cout<<"-1"<<endl;
    }
    else
    {
        cout<<wynik<<endl;
    }
    
    
    // system("pause");
    return 0;
}