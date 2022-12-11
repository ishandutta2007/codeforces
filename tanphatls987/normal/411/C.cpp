#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int a1,a2,b1,b2,c1,c2,d1,d2,n[2][2]={0},s1,s2,i,j;
    cin>>a1>>a2>>b1>>b2>>c1>>c2>>d1>>d2;
    //TH1
    {
        if (c2<a1) {if (d1<b2) n[0][0]=-1;}else
        if (c2>a1) if (d1>b2) n[0][0]=1;
        if (d2<a1) {if (c1<b2) n[0][1]=-1;}else
        if (d2>a1) if (c1>b2) n[0][1]=1;

    }
    {
        if (c1<a2) {if (d2<b1) n[1][1]=-1;}else
        if (c1>a2) if (d2>b1) n[1][1]=1;
        if (d1<a2) {if (c2<b1) n[1][0]=-1;}else
        if (d1>a2) if (c2>b1) n[1][0]=1;
    }
    s2=0;s1=0;
    for(i=0;i<2;i++)
        for(j=0;j<2;j++) if (n[i][j]==1) {s2++;break;}
    if (s2==2) cout<<"Team 2";else
    {
    for(i=0;i<2;i++)
        if (n[i][0]+n[i][1]==-2) {cout<<"Team 1";return(0);}
    cout<<"Draw";
    }
}