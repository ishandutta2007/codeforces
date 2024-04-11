#include <stdio.h>
#include <iostream>

using namespace std;

bool sim(char a, char b) {
  if (tolower(a) == tolower(b)) return true;
  bool aIsZero = (a == '0') || (tolower(a) == 'o');
  bool bIsZero = (b == '0') || (tolower(b) == 'o');
  if ((aIsZero) && (bIsZero)) return true;
  bool aIsOne = (a == '1') || (tolower(a) == 'l') || (tolower(a) == 'i');
  bool bIsOne = (b == '1') || (tolower(b) == 'l') || (tolower(b) == 'i');
  return aIsOne & bIsOne;
}

int main() {
//  freopen("input.txt", "r", stdin);
  string s;
  int n;
  cin >> s;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string p;
    cin >> p;
    if (s.size() != p.size()) continue;
    bool similar = true;
    for (size_t j = 0; j < s.size(); j++) {
      if (!sim(s[j], p[j])) {
        similar = false;
        break;
      }
    }
    if (similar) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
  return 0;
}