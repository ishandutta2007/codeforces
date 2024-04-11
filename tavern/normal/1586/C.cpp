#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 5;

int n, m, q;
int f[maxn];
string s[maxn];

int main(){
  //freopen("C.in", "r", stdin);
  
  cin >> n >> m;
  for(int i = 0; i < n; ++i)
    cin >> s[i];

  for(int j = 1; j < m; ++j){
    f[j] = f[j - 1];
    for(int i = 1; i < n; ++i)
      f[j] += (s[i - 1][j] == 'X' && s[i][j - 1] == 'X');
  }

  cin >> q;
  for(int i = 0; i < q; ++i){
    int l, r; cin >> l >> r; --l, --r;
    if(f[r] - f[l] == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}