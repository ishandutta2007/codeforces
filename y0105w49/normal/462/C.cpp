#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long a[1000007];
long long sums[1000007];

int main() {

  cin >> n;
  for (int i = 0; i<n; i++)
    cin >> a[i];

  sort(a,a+n);

  for (int i = n; --i>=0; )
    sums[i]=sums[i+1]+a[i];

  long long score = sums[0]-a[n-1];

  for (int i = 0; i<n; i++)
    score+=sums[i];

  cout << score << endl;

  return 0;
}