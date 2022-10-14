#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
int max1,k,i,j,m,n,a[100000];
cin>>n;
for (i=0;i<n;i++)
cin>>a[i];
sort(a,a+n);
max1=0;k=1;
for (i=0;i<n-1;i++)
{
if (a[i]==a[i+1]) k++; else k=1;
if (k>max1) max1=k;
}
if (max1<=(n+1)/2) cout<<"YES"<<endl; else cout<<"NO"<<endl;
return 0;
}