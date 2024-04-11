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
    int n;
    cin >> n;
    vector<string> s(n - 2);
    for (auto &S : s)
    {
      cin >> S;
    }
    int p = n - 2;
    bool fulfilled = false;
    for (int i = 1; i < n - 2; i++)
    {
      if (s[i - 1][1] != s[i][0])
      {
        for(int j = 0; j < i; j++) {
          cout << s[j][0];
        }
        cout << s[i - 1][1];
        for(int j = i; j < n - 2; j++) {
          cout << s[j][0];
        }
        cout << s[n - 3][1] << "\n";
        fulfilled = true;
        break;
      }
    }
    if(fulfilled) {
      continue;
    }
    for(int i = 0; i < n - 2; i++) {
      cout << s[i][0];
    }
    cout << s[n - 3][1]<<"b" << "\n";;
  }
}