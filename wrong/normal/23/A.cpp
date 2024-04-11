#include<iostream>
#include<string>

using namespace std;

int main()
{
  string s;
  cin >> s;
  int sol = 0;
  for(int i=0; i<s.size(); ++i) {
    for(int j=i; j<s.size(); ++j) {
      string sub = s.substr(i, j-i+1);
      int last = -1, first = 10000;
      for(int k=s.size()-1; k>=0; --k) {
	if(s.substr(k, sub.size()) == sub) {
	  last = k;
	  break;
	}
      }
      for(int k=0; k<s.size(); ++k) {
	if(s.substr(k, sub.size()) == sub) {
	  first = k;
	  break;
	}
      }
      if(first != last && sol<sub.size()) {
	sol = sub.size();
      }
    }
  }
  cout << sol << endl;
  return 0;
}