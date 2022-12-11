#include <iostream>
#include <fstream>
int n,a[100][100],i,j,m;
using namespace std;

int check(int x)
{
    if (x%2) {cout<<x;return 0;}
    for(i=0;i<x/2;i++)
        for(j=0;j<m;j++) if (a[i][j]!=a[x-i-1][j]) {cout<<x;return 0;}
    check(x/2);
}
int main()
{
    cin>>n>>m;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++) cin>>a[i][j];
    check(n);
}