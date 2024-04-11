#include <iostream>
#include <string>
using namespace std;

string seat[1000];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> seat[i];
  }
  bool ok = false;
  for (int i = 0; i < n; ++i) {
    if (seat[i][0] == 'O' && seat[i][1] == 'O') {
      ok = true;
      seat[i][0] = '+';
      seat[i][1] = '+';
      break;
    }
    if (seat[i][3] == 'O' && seat[i][4] == 'O') {
      ok = true;
      seat[i][3] = '+';
      seat[i][4] = '+';
      break;
    }
  }
  if (ok) {
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
      cout << seat[i] << endl;
    }
  } else {
    cout << "NO" << endl;
  }
  return 0;
}