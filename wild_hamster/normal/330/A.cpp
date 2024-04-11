#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll j,k2,n,k,s,i,k1,a[15],b[15];
int main()
{

cin>>n>>k;
s=0;char c;
for (i=0;i<n;i++)
for (j=0;j<k;j++)
{
cin>>c;
if (c=='S') {a[i]=1;b[j]=1;s++;}
}
for (i=0;i<n;i++) k1+=a[i];
for (i=0;i<k;i++) k2+=b[i];
cout<<n*k-k1*k2<<endl;
return 0;
}