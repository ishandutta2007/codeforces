#include <iostream>
#include <map>
#include <cstring>
#include <string>
using namespace std;
int main()
{
long long k,k1,k2,n,i,j,a[100000];
string c;
getline(cin,c);
k1=-1;k2=-1;i=0;
while (i<c.size())
{
if (k1>0) {while (c[i]!='"') {i++;k2=i;} i++;
cout<<"<";for (j=k1;j<k2;j++) cout<<c[j];cout<<">"<<endl;k1=-1;k2=-1;} else
if (c[i]=='"') k1=i+1; else
if (c[i]!=' ')
{
cout<<"<";
while (c[i]!=' '&&i<c.size()) {cout<<c[i];i++;}
cout<<">"<<endl;
}
i++;
}
return 0;
}