#include <bits/stdc++.h>
using namespace std;
int n,m,a[25][25],b[25][25],i,j,k,x,y,l,r;
int main()
{
    cin>>n>>m;
    for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
    cin>>a[i][j];
    for (i=1;i<=m;i++)
    for (j=1;j<=m;j++){
        for (l=1;l<=n;l++)
        for (r=1;r<=m;r++)
        b[l][r]=a[l][r];
        for (l=1;l<=n;l++)
        swap(b[l][i],b[l][j]);
        k=0;
        for (l=1;l<=n;l++){
            x=0;
            for (r=1;r<=m;r++)
            if (b[l][r]!=r)
            x++;
            if (x>2)k=1;
            //if (i==8 && j==10 && k)cout<<x<<endl;
        }
        if (k==0){cout<<"YES"<<endl;return 0;}
    }
    cout<<"NO"<<endl;
	return 0;
}