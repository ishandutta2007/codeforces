#include <bits/stdc++.h>
using namespace std;
string s,ss;
int i;
int main()
{
cin>>s;
for (i=s.size()-1;i>=0;i--)ss+=s[i];
for (i=0;i<s.size();i++){
if (s[i]>ss[i])swap(s[i],ss[i]);
if (s[i]=='o' && ss[i]=='o')continue;
if (s[i]=='b' && ss[i]=='d')continue;
if (s[i]=='O' && ss[i]=='O')continue;
if (s[i]=='p' && ss[i]=='q')continue;
if (s[i]=='x' && ss[i]=='x')continue;
if (s[i]=='X' && ss[i]=='X')continue;
if (s[i]=='U' && ss[i]=='U')continue;
if (s[i]=='V' && ss[i]=='V')continue;
if (s[i]=='v' && ss[i]=='v')continue;
if (s[i]=='W' && ss[i]=='W')continue;
if (s[i]=='w' && ss[i]=='w')continue;
if (s[i]=='I' && ss[i]=='I')continue;
if (s[i]=='M' && ss[i]=='M')continue;
if (s[i]=='A' && ss[i]=='A')continue;
if (s[i]=='Y' && ss[i]=='Y')continue;
if (s[i]=='H' && ss[i]=='H')continue;
if (s[i]=='T' && ss[i]=='T')continue;
cout<<"NIE"<<endl;
return 0;
}
cout<<"TAK"<<endl;
return 0;
}