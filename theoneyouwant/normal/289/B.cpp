#include<iostream>
#include<algorithm>
using namespace std;

int main()

{
    int n,m,d;
    cin>>n>>m>>d;
    int a[n][m],b[m*n];
    bool c=1;
    int counter1=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
            if(i==0 && j==0)
            {
                counter1=a[0][0]%d;
            }
            else
            {
                if(counter1!=a[i][j]%d)
                {
                    c=0;
                    break;
                }
            }
            b[i*m+j] = a[i][j];
        }
    }
    sort(b,b+m*n);
    int median = b[m*n/2];
    long long int total=0;
    if(c==0)
    {
        cout<<"-1";
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
             //   cout<<i<<" "<<j<<" "<<a[i][j]<<" "<<median<<"\n";
                total+=abs(a[i][j]-median)/d;
            }
        }
        cout<<total;
    }
    return 0;
}