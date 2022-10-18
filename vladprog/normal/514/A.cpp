#include<bits/stdc++.h>

using namespace std;

int main()
{
  string s;
  cin>>s;
  cout<<((char)(((int)s[0]==57)?s[0]:min((int)s[0],105-(int)s[0])));
  for(int i=1;i<s.length();i++)
    cout<<min((int)s[i],105-(int)s[i])-48;
}