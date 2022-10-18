#include<bits/stdc++.h>

using namespace std;

int cs[26],CS[26],ct[26],CT[26];

int main()
{
  string s,t;
  cin>>s>>t;
  for (int i=0;i<s.length();i++)
    if(s[i]<'A')
      cs[(int)s[i]-(int)'a']++;
    else
      CS[(int)s[i]-(int)'A']++;
  for (int i=0;i<t.length();i++)
    if(s[i]<'A')
      ct[(int)t[i]-(int)'a']++;
    else
      CT[(int)t[i]-(int)'A']++;
  int ura=0,opa=0,k;
  for(int i=0;i<26;i++)
  {
    k=min(cs[i],ct[i]);
    ura+=k;
    cs[i]-=k;
    ct[i]-=k;
    
    k=min(CS[i],CT[i]);
    ura+=k;
    CS[i]-=k;
    CT[i]-=k;
    
    k=min(CS[i],ct[i]);
    opa+=k;
    
    k=min(cs[i],CT[i]);
    opa+=k;
    
  }
  cout<<ura<<' '<<opa;
}