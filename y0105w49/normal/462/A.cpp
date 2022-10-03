#include <iostream>

using namespace std;

int main() {

  int n;
  cin >> n;

  int even = 1;

  char grid[n+2][n+2];
  for (int i = 0; i<n+2; i++)
    for (int j = 0; j<n+2; j++)
      grid[i][j]='x';
  for (int i = 0; i<n; i++)
    for (int j = 0; j<n; j++)
      cin >> grid[i+1][j+1];
  for (int i = 1; i<n+1; i++)
    for (int j = 1; j<n+1; j++) {
      int count = 0;
      if (grid[i+1][j]=='o') ++count;
      if (grid[i-1][j]=='o') ++count;
      if (grid[i][j-1]=='o') ++count;
      if (grid[i][j+1]=='o') ++count;
      if (count%2==1) {
        even=0;
        break;
      }
    }
  if (even) cout << "YES" << endl;
  else cout << "NO" << endl;

  return 0;
}