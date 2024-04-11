#include <bits/stdc++.h>
#include <array>
#include <unordered_map>
using namespace std;
template<typename T = int> vector<T> create(size_t n){ return vector<T>(n); }
template<typename T, typename... Args> auto create(size_t n, Args... args){ return vector<decltype(create<T>(args...))>(n, create<T>(args...)); }
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
using ll = long long;
using ull = unsigned long long;
using vpi = vector<pair<int, int>>;
using pii = pair<int, int>;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  for(int i = 1; i < n; i++){
    int p;
    cin >> p;
    p--;
    adj[p].push_back(i);
  }
  vector<ll> sub(n), sum(n);
  auto dfs = [&](auto self, int u, int p) -> void {
    sub[u] = 1;
    for(int v : adj[u]){
      self(self, v, u);
      sub[u] += sub[v];
    }
  };
  dfs(dfs, 0, -1);
  for(int i = 0; i < n; i++){
    sum[0] += sub[i];
  }
  auto fix = [&](auto self, int u, int p) -> void {
    if(p != -1){
      sum[u] = sum[p];
      sum[u] -= sub[u];
      sum[u] += (n - sub[u]);
    }
    for(int v : adj[u]){
      self(self, v, u);
    }
  };
  fix(fix, 0, -1);
  vector<int> is_cent(n);
  for(int i = 0; i < n; i++){
    is_cent[i] = 1;
    for(int j : adj[i]){
      if(sub[j] * 2 > n)
        is_cent[i] = 0;
    }
    if(2 * (n - sub[i]) > n){
      is_cent[i] = 0;
    }
  }
  ll ans = 0;
  using bset = bitset<1000100>;
  for(int i = 0; i < n; i++){
    if(is_cent[i]){
      vector<int> szs(n + 1);
      for(int j : adj[i]){
        szs[sub[j]]++;
      }
      if(n - sub[i]){
        szs[n - sub[i]]++;
      }
      for(int j = 0; j < n; j++){
        if(szs[j] > 2){
          int rem = 1;
          if(szs[j] % 2 == 0)
            rem++;
          int out = szs[j] - rem;
          szs[j] = rem;
          szs[j * 2] += out / 2;
        }
      }
      bset can;
      can.set(0);
      for(int j = 0; j < n; j++){
        for(int k = 0; k < szs[j]; k++){
          can = can | (can << j);
        }
      }
      ll val = sum[i];
      ll best = 0;
      for(int j = 0; j < n; j++){
        if(can[j]){
          best = max(best, 1ll * j * (n - 1 - j));
        }
      }
      val += best;
      ans = max(ans, val);
    } else {
      ll val = sum[i];
      vector<ll> got;
      for(int j : adj[i]){
        got.push_back(sub[j]);
      }
      if(n - sub[i]){
        got.push_back(n - sub[i]);
      }
      ll all = accumulate(got.begin(), got.end(), 0ll);
      ll mx = *max_element(got.begin(), got.end());
      all -= mx;
      val += all * mx;
      ans = max(ans, val);
    }
  }
  cout << ans << '\n';
  return 0;
}