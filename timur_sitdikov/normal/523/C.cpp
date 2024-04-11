
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int getpos(const string& src, const string& dst) {
 int i, j;
 i = j = 0;
 while (i < src.size() && j < dst.size()) {
  if (src[i] == dst[j]) {
   ++i;
  }  
  ++j;
 }
 if (i < src.size()) return -1;
 return j;
}

int main () {

 string s;
 string t;
 cin >> s;
 cin >> ws >> t;
 int n = t.size();
 
 int left = getpos(s, t);
 if (left == -1) {
  cout << 0;
  return 0;
 } 
 reverse(s.begin(), s.end());
 reverse(t.begin(), t.end());
 int right = n + 1 - getpos(s, t);
 if (left >= right) {
  cout << 0;
 } else {
  cout << right - left;
 }
 
 return 0;
}