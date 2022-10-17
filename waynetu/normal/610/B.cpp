#include <iostream>
using namespace std;

int main() {
  long long int n;
  long long int a[200000];

  long long int min = 1000000001;
  cin >> n;
  long long int mini;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] < min) {
      mini = i;
      min = a[i];
    }
  }
  long long int max = 0;
  long long int dis = 0;
  long long int start = -1;
  for (long long int i = 0; i < n; ++i) {
    if (a[i] == min) {
      if (start != -1) {
        dis = i - start - 1;
        if (dis > max) max = dis;
      }
      start = i;
    }
  }
  long long int first;
  long long int i = 0;
  while (true) {
    if (a[i] == min) {
      first = i;
      break;
    }
    i++;
  }
  dis = n - start + first - 1;
  if (dis > max) max = dis;
  cout << min * n + max << endl;
  return 0;
}