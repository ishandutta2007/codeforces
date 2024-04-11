#include<iostream>

using namespace std;

int main()
{
  int n, x, a[100], b[100];

  while(cin >> n) {
    cin >> x;

    for(int i=0; i<n; ++i) {
      cin >> a[i] >> b[i];
    }

    bool ok = true;

    for(int i=1; i<n; ++i) {
      int ex[7] = {0};
      ex[a[i]] = ex[b[i]] = ex[7-a[i]] = ex[7-b[i]] = 1;

      if(ex[x] == 1) {
        ok = false;
        break;
      }

      x = 7 - x;
    }

    cout << (ok ? "YES" : "NO") << endl;
  }

  return 0;
}