#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string.h>
using namespace std;
typedef long long ll;
int main()
{
string c;
ll s,j,min1,i,m,n,k,k1,o,a[1000];
cin>>n;
while(n--)
{
cin>>c;
if (c.size()>10)
cout<<c[0]<<c.size()-2<<c[c.size()-1]<<endl; else cout<<c<<endl;
}
return 0;
}