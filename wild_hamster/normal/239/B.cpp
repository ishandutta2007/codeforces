#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string.h>
using namespace std;
typedef long long ll;
ll a[15],y,k2,k3,r1,z,k4,r,max1,k5,k1,min1,b[1005],n1,n,m,k,i,j;
vector<char > f;
int main()
{
string s,s1;
cin>>k>>n;
cin>>s;
for (i=0;i<n;i++)
{
for (j=0;j<10;j++) a[j]=0;
cin>>k1>>k2;
s1.clear();
for (j=k1-1;j<=k2-1;j++)
s1.push_back(s[j]);
//cout<<s1<<endl;
j=0;
k3=1;
z=0;
while (j>=0&&j<s1.size())
{
//      cout<<j<<" "<<s1<<endl;
if ((int)s1[j]>=(int)'0'&&(int)s1[j]<=(int)'9')
{
a[(int)s1[j]-(int)'0']++;
if (s1[j]=='0') s1[j]='-'; else s1[j]=(char)((int)s1[j]-1);
j+=k3;
z=0;
} else
if (s1[j]=='>')
{
if (z) s1[k4]='-';
k4=j;
z=1;
k3=1;
j+=k3;
} else
if (s1[j]=='<')
{
if (z) s1[k4]='-';
k4=j;
z=1;
k3=-1;
j+=k3;
} else
j+=k3;
}
for (j=0;j<10;j++)
cout<<a[j]<<" ";
cout<<endl;
}
return 0;
}