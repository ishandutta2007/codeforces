#include<iostream>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    if(n>=m)
    {
        cout<<m+1<<endl;
        for(int i=0;i<m+1;i++)
        {
            cout<<i<<" "<<m-i<<endl;
        }
    }
    else
    {
        cout<<n+1<<endl;
        for(int i=0;i<n+1;i++)
        {
            cout<<i<<" "<<n-i<<endl;
        }
    }
    return 0;
}