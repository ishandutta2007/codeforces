/**
 *    author:  tourist
 *    created: 01.06.2019 18:45:07       
**/
#include <bits/stdc++.h>

using namespace std;

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

vector<int> least = {0, 1};
vector<int> primes;
int precalculated = 1;

void RunLinearSieve(int n) {
  n = max(n, 1);
  least.assign(n + 1, 0);
  primes.clear();
  for (int i = 2; i <= n; i++) {
    if (least[i] == 0) {
      least[i] = i;
      primes.push_back(i);
    }
    for (int x : primes) {
      if (x > least[i] || i * x > n) {
        break;
      }
      least[i * x] = x;
    }
  }
  precalculated = n;
}

const int N = 100010;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int mx = *max_element(a.begin(), a.end());
  RunLinearSieve(mx);
  vector<int> pid(mx + 1, -1);
  int pcnt = 0;
  vector<vector<int>> z(n);
  for (int i = 0; i < n; i++) {
    int x = a[i];
    int last = -1;
    while (x > 1) {
      if (least[x] != last) {
        if (pid[least[x]] == -1) {
          pid[least[x]] = pcnt++;
        }
        z[i].push_back(pid[least[x]]);
        last = least[x];
      }
      x /= least[x];
    }
  }
  vector<vector<int>> ids(pcnt);
  for (int i = 0; i < n; i++) {
    for (int j : z[i]) {
      ids[j].push_back(i);
    }
  }
  vector<bitset<N>> bitsets;
  vector<int> bitset_id(pcnt, -1);
  for (int i = 0; i < pcnt; i++) {
    if ((int) ids[i].size() >= n / 239) {
      bitset_id[i] = (int) bitsets.size();
      bitsets.emplace_back();
      for (int j : ids[i]) {
        bitsets.back()[j] = 1;
      }
    }
  }
  bitset<N> alive;
  for (int i = 0; i < n; i++) {
    alive[i] = 1;
  }
  vector<char> visited_value(mx + 1, 0);
  vector<vector<int>> comps;
  vector<int> alone;
  for (int st = 0; st < n; st++) {
    if (alive[st] == 0) {
      continue;
    }
    vector<int> que(1, st);
    alive[st] = 0;
    for (int b = 0; b < (int) que.size(); b++) {
      int i = que[b];
      if (visited_value[a[i]]) {
        continue;
      }
      visited_value[a[i]] = 1;
      bitset<N> go = alive;
      for (int j : z[i]) {
        if (bitset_id[j] == -1) {
          for (int u : ids[j]) {
            go[u] = 0;
          }
        } else {
          go ^= (go & bitsets[bitset_id[j]]);
        }
      }
      for (int u = go._Find_first(); u < n; u = go._Find_next(u)) {
        que.push_back(u);
        alive[u] = 0;
      }
    }
    debug(que);
    if (que.size() == 1) {
      alone.push_back(que[0]);
    } else {
      comps.push_back(que);
    }
  }
  vector<int> ret;
  if ((int) alone.size() + (int) comps.size() >= k) {
    for (auto& c : comps) {
      alone.push_back(c[0]);
    }
    alone.resize(k);
    ret = alone;
  } else {
    vector<int> order(comps.size());
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
      return comps[i].size() > comps[j].size();
    });
    int take = 0;
    int sum = 0;
    while (sum < k - 1) {
      sum += (int) comps[take].size();
      take++;
    }
    if (sum == k - 1) {
      comps[0].pop_back();
    }
    for (auto& v : comps) {
      for (int u : v) {
        ret.push_back(u);
      }
    }
  }
  for (int i = 0; i < k; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << ret[i] + 1;
  }
  cout << '\n';
  return 0;
}