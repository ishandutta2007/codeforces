#include <iostream>
using namespace std;

int main()
{
    long int n,i,j,a,b,h[24][60],ans;
    for (i=0;i<24;i++)
        for (j=0;j<60;j++) h[i][j]=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a>>b;
        h[a][b]++;
    }
    ans=0;
    for(i=0;i<24;i++)
        for (j=0;j<60;j++) if (h[i][j]>ans) ans=h[i][j];
    cout<<ans;
}