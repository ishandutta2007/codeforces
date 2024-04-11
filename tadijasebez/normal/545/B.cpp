#include <bits/stdc++.h>
using namespace std;
int main()
{
string s[2],p;
cin>>s[0]>>s[1];
int j=0;
for(int i=0;i<s[0].size();i++)
{
if(s[0][i]==s[1][i]) p+=s[0][i];
else p+=s[j][i],j^=1;
}
if(j) printf("impossible");
else cout<<p;
return 0;
}