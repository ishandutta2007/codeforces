#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
typedef double db;
#define tr 1000000007
//map <ll,ll> a,b,c;
ll i,p,q,n,min1,k,k1,k2,a[100500],b[100500];
int main() 
{
string s,s1,s2;
cin>>n>>k;
cin>>s;
s1=s;s2=s;
if (k==2)
{
for (i=0;i<n;i++)
{
s1[i]=(char)((int)'A'+i%2);
s2[i]=(char)((int)'B'-i%2);
if (s1[i]!=s[i]) k1++;
if (s2[i]!=s[i]) k2++;
}
if (k1>k2)
{
cout<<k2<<endl;
cout<<s2;
} else
{
cout<<k1<<endl;
cout<<s1;
}
return 0;
}
k1=0;
i=1;
while (i<n)
{
if (s[i]==s[i-1])
{
k1++;
for (int j=0;j<k;j++)
if (char((int)'A'+j)!=s[i-1]&&char((int)'A'+j)!=s[i+1]) s[i]=char((int)'A'+j);
i++;
}
i++;
}
cout<<k1<<endl;
cout<<s;
return 0;
}