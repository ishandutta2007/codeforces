#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

const int N = 5e6 + 10;
int mp[N][2], sum[N]; 
int cnt = 1;
void add(int x) {
  int v = 1;
  for (int i = 30; i >= 0; i--) {
    int to = (x >> i) & 1;
    if (!mp[v][to]) {
      mp[v][to] = ++cnt;
    }
    v = mp[v][to];
    sum[v]++;
  }
}

int a[N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i =1 ; i <= n; i++) {
    cin >> a[i];
  }  
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    add(x);
  }
  for (int i = 1; i <= n; i++) {
    int cur = 0, v = 1;
    for (int j = 30; j >= 0; j--) {
      if (sum[mp[v][(a[i] >> j) & 1]] > 0) {
        v = mp[v][(a[i] >> j) & 1];
      }
      else {
        cur += 1 << j;
        v = mp[v][((a[i] >> j) & 1) ^ 1];
      }
      sum[v]--;
    }
    cout << cur << ' ';
  }
  cout << '\n';
}