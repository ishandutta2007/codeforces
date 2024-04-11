#include <iostream>
#include <map>
using namespace std;
int main()
{
long long k,n,i,j,a[100000];
cin>>n;
for (i=0;i<n;i++) cin>>a[i];
map <long long,int> f;
k=0;
for (i=0;i<n;i++)
{
f[a[i]]++;
if (a[i]!=0)
if (f[a[i]]==2) k++;
else if (f[a[i]]>2) {cout<<-1<<endl;return 0;}
}
cout<<k<<endl;
return 0;
}