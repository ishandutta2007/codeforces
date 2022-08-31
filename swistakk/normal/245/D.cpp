#include <iostream>
using namespace std;
int b[105][105];
int a[105];
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin>>b[i][j];
        }
    }
    int pot=1;
    while(pot<1001*1001*1000)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(i!=j)
                {
                    if( pot&b[i][j])
                    {
                        a[i]+=pot;
                        break;
                    }
                }
            }
        }
        pot*=2;
    }
    for(int i=1; i<=n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    // system("pause");
    return 0;
}