#include <bits/stdc++.h>

#define ar array
#define ll long long
#define pb push_back

#define int long long
using namespace std;
constexpr int mxN = 1e4;
int n, m, x, y, t1, t2;
string labels[mxN];

int32_t main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int &i : a) 
    {
      cin >> i;
    }

    int g1 = 0, g2 = 0;

    for(int i = 0; i < n; i += 2) {
      g1 = __gcd(g1, a[i]);
    }
    for(int i = 1; i < n; i += 2) {
      g2 = __gcd(g2, a[i]);
    }

    bool workingFirst = true, workingSecond = true;


    for(int i = 0; i < n; i += 2) {
      workingFirst &= a[i] % g2 != 0;
    }

    for(int i = 1; i < n; i += 2) {
      workingSecond &= a[i] % g1 != 0;
    }
    if(workingFirst) {cout << g2 << "\n";}
    else if(workingSecond) {cout << g1 << "\n";}
    else cout << 0 << "\n";
  }
}