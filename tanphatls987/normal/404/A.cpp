#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    char a[301][301],last;
    int n,i,j;
    cin>>n;
    for(i=0;i<n;i++) cin>>a[i];
    last=a[0][0];
    for(i=0;i<n;i++)
    {
        if ((a[i][i]!=last)||(a[i][n-i-1]!=last)) {cout<<"NO";return 0;}
    }
    last=a[0][1];
    if (last==a[0][0]) {cout<<"NO";return 0;}
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
    {
        if ((a[i][j]!=last)&&(j!=i)&&(j!=n-i-1)) {cout<<"NO";return 0;}
    }
    cout<<"YES";
}