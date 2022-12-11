#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int n,i,j,k;
    cin>>n;
    for (i=1,j=n*n;i<=n*n/2,j>n*n/2;i++,j--)
    {
        cout<<i<<" "<<j<<" ";
        k++;
        if (k%(n/2)==0) cout<<endl;
    }
}