#include <iostream>
#include <fstream>
using namespace std;
long long t,j,n,a[10000001],i,p;
main()
{
cin>>t;
for (j=1;j<=t;j++)
{
    cin>>n;
    a[0]=1;
    for (i=1;a[i-1]<n;i++)
    a[i]=a[i-1]*2;
    a[i]=a[i-1]*2;
    i--;
    if (a[i]==n)
    i++;
    //cout<<a[i]<<" ";
    p=-2*(a[i]-1);
    if (n%2==0) p+=n/2*(n+1);
    else p+=(n+1)/2*n;
    /*if (n==1000000000)
    cout<<"499999998352516354"<<endl;
    else*/
    cout<<p<<endl;
}
}