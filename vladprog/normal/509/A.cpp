#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int m=1,a[n][n];
    memset(a,0,sizeof(a));
    for(int i=0;i<n;i++)
        a[i][0]=a[0][i]=1;
    for(int i=1;i<n;i++)
        for(int j=1;j<n;j++)
            m=max(m,a[i][j]=a[i-1][j]+a[i][j-1]);
    cout<<m;
}