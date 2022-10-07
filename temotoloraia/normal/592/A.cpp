#include <iostream>
using namespace std;
char a[8][8];
int min1=8,min2=8,i,j,i1,j1,ans;
main()
{
    for (i=0;i<8;i++)
    for (j=0;j<8;j++)
    cin>>a[i][j];
    for (i=0;i<8;i++)
    for (j=0;j<8;j++)
    {
        ans=0;
        if (a[i][j]=='W')
        {
            for (i1=i-1;i1>=0;i1--)
            if (a[i1][j]=='B')
            {
            ans=1;
            break;
            }
            if (ans==0 && i<min1)
            min1=i;
        }
        else if (a[i][j]=='B')
        {
            for (i1=i+1;i1<8;i1++)
            if (a[i1][j]=='W')
            {
            ans=1;
            break;
            }
            if (ans==0 && 7-i<min2)
            min2=7-i;
        }
    }
    if (min1<=min2)
    cout<<"A"<<endl;
    else
    cout<<"B"<<endl;
}