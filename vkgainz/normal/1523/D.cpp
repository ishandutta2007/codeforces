#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, p; cin >> n >> m >> p;

  string in[n];
  ll val[n];
  memset(val, 0, sizeof(val));
  for(int i = 0; i < n; i++) {
    cin >> in[i];
    for(int j = 0; j < m; j++) {
      if(in[i][j] - '0') val[i] += 1LL << j;
    }
  }
  
  ll ans = 0LL;
  for(int i = 0; i < 40; i++) {
    int test = (rand() * (RAND_MAX) + rand()) % (int) n;
    if(test < 0) test += n;

    vector<int> bits;
    for(int j = 0; j < m; j++) {
      if(val[test] & (1LL << j)) 
        bits.push_back(j);
    }
    map<ll, ll> forward, backward;
    for(int msk = 0; msk < (1 << (int) bits.size()); msk++) {
      ll x = 0LL;
      for(int j = 0; j < (int) bits.size(); j++) {
        if(msk & (1 << j)) 
          x += (1LL << bits[j]);
      }
      forward[msk] = x;
      backward[x] = msk;
    }
    ll store[n];
    vector<int> freq(1 << (int) bits.size());
    for(int j = 0; j < n; j++) {
      store[j] = val[j] & val[test];
      ++freq[backward[store[j]]];
    }

    for(int j = 0; j < (int) bits.size(); j++) {
      for(int msk = (1 << (int) bits.size()) - 1; msk >= 0; msk--) {
        if(msk & (1 << j)) continue;
        else 
          freq[msk] += freq[msk ^ (1 << j)];
      }
    }
    for(int msk = 0; msk < (1 << (int) bits.size()); msk++) {
      if(freq[msk] >= (n + 1) / 2) {
        if(__builtin_popcountll(forward[msk]) > __builtin_popcountll(ans))
          ans = forward[msk];
      }
    }
  }
  
  string ret = "";
  for(int j = 0; j < m; j++) {
    if(ans & (1LL << j)) 
      ret += '1';
    else ret += '0';
  }

  cout << ret;
}