#include <iostream>

using namespace std;

void answer(int x) {
  cout << "! " << x << endl;
}

bool y_is_larger(int x, int y) {
  cout << "? " << x << " " << y << endl;

  char res;
  cin >> res;
  if (res == 'e') exit(0);
  return res == 'y';
}

void solve() {
  // a=1 
  if (!y_is_larger(0, 1)) {
    answer(1);
    return;
  }

  int p = 0;
  while (y_is_larger(1 << p, 1 << (p + 1))) ++p;

  // a in (l, r]
  int l = (1 << p), r = (1 << (p + 1));
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (y_is_larger(1 << p, mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }

  answer(r);
}

int main() {
  while (true) {
    string s;
    cin >> s;

    if (s == "start") {
      solve();
    } else {
      break;
    }
  }
  return 0;
}