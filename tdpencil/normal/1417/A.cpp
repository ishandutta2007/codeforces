// chrono::system_clock::now().time_since_epoch().count()
#include<bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = (int)1e3 + 5;

int n, k;
int arr[MAXN];

void solve() {
  scanf("%d %d", &n, &k);
  
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &arr[i]);
  }
  
  int mn = min_element(arr + 1, arr + n + 1) - arr;
  int ans = 0;
  
  for (int i = 1; i <= n; ++i) {
    if (i != mn) {
      while (arr[i] + arr[mn] <= k) {
        arr[i] += arr[mn];
        ++ans;
      }
    }
  }
  
  printf("%d\n", ans);
}

int main() {
  int tt;
  scanf("%d", &tt);
  
  while (tt--) {
    solve();
  }

  return 0;
}