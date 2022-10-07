#include <bits/stdc++.h>
using namespace std;
string s;
int i=-1,j,p;
main()
{
cin>>s;
for (j=1;j<s.size();j++)
if (s[j]>='a' && s[j]<='z')
p=1;
if (p==1)
cout<<s<<endl;
else
{
for (i=0;i<s.size();i++)
{
if (s[i]>='a' && s[i]<='z')
cout<<char(int(s[i])-32);
else
cout<<char(int(s[i])+32);
}
}
}