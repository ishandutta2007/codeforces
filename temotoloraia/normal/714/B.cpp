#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
int n,a[100005],i,j,x=-1,y=-1,z=-1,t=-1,b[3];
int main()
{
    cin>>n;
    for (i=1;i<=n;i++){cin>>a[i];
    if (x==a[i] || y==a[i] || z==a[i])continue;
    if (x==-1)x=a[i];
    else if (y==-1)y=a[i];
    else if (z==-1)z=a[i];
    else if (t==-1) t=a[i];
    }
    b[0]=x;
    b[1]=y;
    b[2]=z;
    sort(b,b+3);
    x=b[0];
    y=b[1];
    z=b[2];
    if (t!=-1){cout<<"NO"<<endl;}
    else if (x==-1){cout<<"YES"<<endl;}
    else if (y*2==x+z)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;/*
cout<<x<<" "<<y<<" "<<z<<" "<t<<endl;
  system("pause");*/
    return 0;
}