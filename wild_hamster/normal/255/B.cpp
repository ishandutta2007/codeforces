#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <time.h>
using namespace std;
int k1,k2,j,n,i,a[1000005];
int main()
{
    string s;
char c;
cin>>s;
i=0;
k1=0;k2=0;
for (i=0;i<s.size();i++)
if (s[i]=='x') k1++; else k2++;
if (k1>k2)
for (i=0;i<k1-k2;i++) cout<<'x'; else
for (i=0;i<k2-k1;i++) cout<<'y';
/*while (i<s.size())
{
while (s[i]==c) {k1++;i++;}
if (c=='x') c='y'; else c='x';
if (k1>k2)
for (j=i-k1-k2;j<i-k1-k2+2*min(k1,k2);j++) s[j]='-'; else
for (j=i-2*min(k1,k2);j<i;j++) s[j]='-';
k2=k1-min(k1,k2);
k1=0;
}
for (i=0;i<s.size();i++)
if (s[i]!='-') cout<<s[i];*/
return 0;
}