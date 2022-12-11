#include <iostream>

using namespace std;

int main()
{
    int n,a[100],i,j,tmp;
    cin>>n;
    for (i=0;i<n;i++) cin>>a[i];
    for (i=0;i<n-1;i++)
    for (j=i+1;j<n;j++) if (a[i]>a[j]) {tmp=a[i];a[i]=a[j];a[j]=tmp;}
    for(i=0;i<n;i++) cout<<a[i]<<" ";
}