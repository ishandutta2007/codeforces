#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <bits/stdc++.h>
using namespace std;
int ans[8],i,j,x,p,k;
string s;
char ch[8]={'[',']','(',')','{','}','<','>'};
stack<char>S;
int main()
{
cin>>s;
for (i=0;i<s.size();i++)
{
for (j=0;j<8;j++)
if (s[i]==ch[j])
break;
ans[j]++;
if (j%2==0)
S.push(s[i]);
else
{
if (S.size()>0)
{
for (k=0;k<8;k++)
if (S.top()==ch[k])
break;
if (j!=k+1)
p++;
S.pop();
}
else
{
cout<<"Impossible"<<endl;
return 0;
}
}
}
if (S.size()!=0)
{
cout<<"Impossible"<<endl;
return 0;
}
cout<<p<<endl;
return 0;
}