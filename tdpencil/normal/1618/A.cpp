#include <bits/stdc++.h>

#define ar array
#define ll long long
#define pb push_back

using namespace std;
constexpr int mxN = 1e4;
int n, m, x, y, t1, t2;
string labels[mxN];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--)
  {
    vector<int> a(7);
    for(int &i : a) { cin >> i; }
    cout << a[0] << " " << a[1] << " " << a[7 - 1] - a[0] - a[1] << "\n";


  }
}