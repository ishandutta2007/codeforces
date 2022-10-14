#include <bits/stdc++.h>
 
using namespace std;
 
bool findPartiion(int arr[], int n)
{
    int sum = 0;
    int i, j;
 
    // Calculate sum of all elements
    for (i = 0; i < n; i++)
        sum += arr[i];
 
    if (sum % 2 != 0)
        return false;
 
    bool part[sum / 2 + 1][n + 1];
 
    // initialize top row as true
    for (i = 0; i <= n; i++)
        part[0][i] = true;
 
    // initialize leftmost column,
    // except part[0][0], as 0
    for (i = 1; i <= sum / 2; i++)
        part[i][0] = false;
 
    // Fill the partition table in bottom up manner
    for (i = 1; i <= sum / 2; i++) {
        for (j = 1; j <= n; j++) {
            part[i][j] = part[i][j - 1];
            if (i >= arr[j - 1])
                part[i][j] = part[i][j]
                             || part[i - arr[j - 1]][j - 1];
        }
    }
 
    /* // uncomment this part to print table
    for (i = 0; i <= sum/2; i++)
    {
    for (j = 0; j <= n; j++)
        cout<<part[i][j];
    cout<<endl;
    } */
 
    return part[sum / 2][n];
}
 
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (!findPartiion(a, n)) {
    cout << 0 << '\n';
    return 0;
  }
  vector<int> id(n);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&](int i, int j) {
    return a[i] < a[j];
  });
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (a[i] % 2 == 1) {
      cout << 1 << '\n' << i + 1 << '\n';
      return 0;
    }
  }
  for (int i = 0; i < n; i++) {
    int b[n - 1], cnt = 0;
    for (int j = 0; j < n; j++) {
      if (i != j) {
        b[cnt++] = a[j];
      }
    }
    if (!findPartiion(b, n - 1)) {
      cout << 1 << '\n' << i + 1 << '\n';
      return 0;
    }
  }
  assert(false);
  return 0;
}