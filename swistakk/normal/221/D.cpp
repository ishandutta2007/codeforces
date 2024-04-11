#include <iostream>
#include <vector>
using namespace std;
int licz[1001*101];
int t[1001*101];
vector<int> zap[1001*101];
int wyn[1001*101];
int z[1001*101][3];
int main()
{
    int n, m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
        if(t[i]<=n)
        {
            licz[t[i]]++;
        }
    }
    for(int i=1; i<=m; i++)
    {
        cin>>z[i][1]>>z[i][2];
        zap[z[i][1]].push_back(i);
    }
    int pocz, kon, l, last;
    for(int i=1; i<=n; i++)
    {
        if(licz[i]>=i)
        {
            pocz=1;
            kon=0;
            l=0;
            while(l<i)
            {
                kon++;
                if(t[kon]==i)
                {
                    l++;
                }
            }
            last=kon;
            while(kon<=n-1 && t[kon+1]!=i)
            {
                kon++;
            }
            while(kon<=n)
            {
                do
                {
                    for(int j=0; j<zap[pocz].size(); j++)
                    {
                        if( z[ zap[pocz][j] ][2]>=last && z[ zap[pocz][j] ][2]<=kon)
                        {
                            wyn[zap[pocz][j]]++;
                        }
                    }
                    pocz++;
                }
                while(t[pocz-1]!=i);
                
                kon++;
                last=kon;
                while(kon<=n-1 && t[kon+1]!=i)
                {
                    kon++;
                }
            }
        }
    }
    for(int i=1; i<=m; i++)
    {
        cout<<wyn[i]<<endl;
    }
    //system("pause");
    return 0;
}
 /*
7 2
3 1 2 2 3 3 7
1 7
3 4
*/