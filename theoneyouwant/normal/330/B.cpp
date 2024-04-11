#include<iostream>
using namespace std;

int main()
{
    int n,m,a;
    cin>>n>>m;
    int b[n+1];
    for(int i=0;i<n+1;i++)
    {
        b[i]=1;
    }
    cout<<n-1<<endl;
    for(int i=0;i<2*m;i++)
    {
        cin>>a;
        b[a]=0;
    }
    int j=n+1;
    for(int i=0;i<n+1;i++)
    {
        if(b[i]==1 && i!=0)
        {
            j=i;
            break;
        }
    }
    if(j!=(n+1))
    {
        for(int i=0;i<n;i++)
        {
            if((i+1)==j)
            {
                continue;
            }
            cout<<i+1<<" "<<j<<endl;
        }
    }
    return 0;
}