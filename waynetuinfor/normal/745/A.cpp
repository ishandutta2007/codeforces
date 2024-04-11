#include <string>
#include <set>
#include <iostream>
using namespace std;

string s;
set<string> st;
void cyclic(string&);

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> s;
  for (int i = 0; i < s.length(); ++i) {
    st.insert(s);
    cyclic(s);
  }
  cout << (int)st.size() << '\n';
  return 0;
}

void cyclic(string& s) {
  char c = s[s.length() - 1];
  for (int i = s.length() - 1; i > 0; --i) s[i] = s[i - 1];
  s[0] = c;
}