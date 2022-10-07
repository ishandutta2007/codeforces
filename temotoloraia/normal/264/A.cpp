#include<bits/stdc++.h>
using namespace std;
vector<int> l;
main()
{
string s;
cin>>s;
for(int i=0; i<s.size(); i++)
if(s[i]=='l') l.push_back(i+1);
else printf("%d\n",i+1);
for(int i=l.size()-1; i>=0; i--)
printf("%d\n",l[i]);
    
}