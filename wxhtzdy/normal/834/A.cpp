#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  char a, b;
  cin >> a >> b;
  int n;
  cin >> n; 
  char c1[4] = {'^', '>', 'v', '<'};
  char c2[4] = {'^', '<', 'v', '>'};
  int pos1 = 0;
  for (int i = 0; i < 4; i++) {
    if (a == c1[i]) {
      pos1 = i;
    }
  }
  bool cc = false;
  if (c1[(pos1 + n) % 4] == b) {
    cc = true;
  }
  int pos2 = 0;
  for (int i = 0; i < 4; i++) {
    if (a == c2[i]) {
      pos2 = i;
    }
  }
  bool ccc = false;
  if (c2[(pos2 + n) % 4] == b) {
    ccc = true;
  }
  if (cc == ccc) {
    cout << "undefined";
  } else {
    if (cc) {
      cout << "cw";
    } else {
      cout << "ccw"; 
    }
  }
  return 0;   
}