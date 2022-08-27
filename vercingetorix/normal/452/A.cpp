#include <iostream>
#include <math.h>
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

  int n,k;
  cin>>n;
  char c;
  std::vector<std::string> s;
  std::string ss;
  s.push_back("vaporeon");
	  s.push_back("jolteon");
	  s.push_back("flareon");
	  s.push_back("espeon");
	  s.push_back("umbreon");
	  s.push_back("leafeon");
	  s.push_back("glaceon");
	  s.push_back("sylveon");
  for(int i=0;i<n;i++){
	  cin>>c;
	  ss.push_back(c);
  }
  for(int i=0; i<s.size();i++){
	  if(s[i].length()!=ss.length()) continue;
	  bool f=true;
	  int j;
	  for(j=0;j<ss.length();j++){
		  if((ss[j]!='.')&&(ss[j]!=s[i][j])) f=false;
	  }
	  if(f){
		  cout<<s[i];
		  return 0;
	  }
  }
  
//std::vector<int> a;

  /*int a;
  cin >> a;
  vector<int> b;
  b.push_back(a);
  cout << b[0];
  */

  return 0;
}