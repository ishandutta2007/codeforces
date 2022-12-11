#include <iostream>
using namespace std;

int main()
{
    int a[101]={0},n,m,i,j,tmp;
    cin>>n>>m;
    for (i=0;i<m;i++)
    {
        cin>>tmp;
        for(j=tmp;j<=n;j++) if (a[j]) break; else a[j]=tmp;
    }
    for(i=1;i<=n;i++) cout<<a[i]<<" ";
}