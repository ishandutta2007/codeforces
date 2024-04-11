#include <bits/stdc++.h>
using namespace std;

const int B = 200;

mt19937 rng(uint64_t(new char));

int rand_int(int a, int b) {
  return uniform_int_distribution<int>(a, b)(rng);
}

int p;

int mod_inv(int a) {
  int res = 1;
  int b = p - 2;
  while (b) {
    if (b % 2) {
      res = 1LL * res * a % p;
    }
    a = 1LL * a * a % p;
    b /= 2;
  }
  return res;
}

pair<int, vector<int>> gen(int a) {
  vector<int> path;
  for (int i = 0; i < B / 2; ++i) {
    int type = rand_int(1, 3);
    path.push_back(type);
    if (type == 1) {
      ++a;
      if (a == p) {
        a = 0;
      }
    } else if (type == 2) {
      --a;
      if (a == -1) {
        a = p - 1;
      }
    } else {
      a = mod_inv(a);
    }
  }
  return make_pair(a, path);
}

void print(vector<int>& a, vector<int>& b) {
  cout << B << "\n";
  for (int i : a) {
    cout << i << " ";
  }
  reverse(b.begin(), b.end());
  for (int i : b) {
    cout << (i == 3 ? i : 3 - i) << " ";
  }
  cout << "\n";
  exit(0);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int u, v;
  cin >> u >> v >> p;

  map<int, vector<int>> path_u;
  map<int, vector<int>> path_v;
  vector<int> path;
  int a;

  while (true) {
    tie(a, path) = gen(u);
    if (path_v.count(a) == 1) {
      print(path, path_v[a]);
    }
    path_u[a] = path;

    tie(a, path) = gen(v);
    if (path_u.count(a) == 1) {
      print(path_u[a], path);
    }
    path_v[a] = path;
  }
}