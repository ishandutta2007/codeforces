#include <iostream>
#include <cmath>
using namespace std;
int main()
{
int a[100500],i,n;
cin>>n;
a[0]=0;int rez=2*n-1;
for (i=1;i<=n;i++) cin>>a[i];
for (i=0;i<n;i++) rez+=abs(a[i]-a[i+1]);
cout<<rez<<endl;
return 0;
}