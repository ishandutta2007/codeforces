#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
 
  int a,k;
int ans=0;
std::string s;
  //cin >> a >> k;
cin>>s;
cin>>k;
  int zmax=0;
  int zn[26];
  for(int i=0; i<26; i++){
      int x;
      cin>>x;
      if(x>zmax) zmax=x;
      zn[i]=x;
  }
  
  for(int i=0;i<s.length();i++){
      ans+=(i+1)*(zn[s[i]-'a']);
  }
  ans+=s.length()*k*zmax;
  ans+=(k*(k+1))/2*zmax;
  cout << ans;
  //cout<<coll;
 //cout << s << s.length() << s[2];
  return 0;
}