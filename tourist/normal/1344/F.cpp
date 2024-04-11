/**
 *    author:  tourist
 *    created: 06.05.2020 19:21:59       
**/
#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
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

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
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

string let = "WRYB";

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> what(n, vector<int> {1, 2});
  const int N = 2048;
  vector<bitset<N>> mat;
  vector<int> R;
  for (int i = 0; i < k; i++) {
    string foo;
    int cnt;
    cin >> foo >> cnt;
    if (foo == "mix") {
      bitset<N> row0;
      bitset<N> row1;
      for (int j = 0; j < cnt; j++) {
        int id;
        cin >> id;
        --id;
        for (int x = 0; x < 2; x++) {
          if (what[id][0] & (1 << x)) {
            row0[id * 2 + x] = 1;
          }
        }
        for (int x = 0; x < 2; x++) {
          if (what[id][1] & (1 << x)) {
            row1[id * 2 + x] = 1;
          }
        }
      }
      string bar;
      cin >> bar;
      int num = (int) let.find(bar[0]);
      mat.push_back(row0);
      R.push_back(num & 1);
      mat.push_back(row1);
      R.push_back((num >> 1) & 1);
    } else {
      for (int j = 0; j < cnt; j++) {
        int id;
        cin >> id;
        --id;
        if (foo == "RY") {
          swap(what[id][0], what[id][1]);
        }
        if (foo == "RB") {
          what[id][1] ^= what[id][0];
        }
        if (foo == "YB") {
          what[id][0] ^= what[id][1];
        }
      }
    }
  }
  int sz = (int) mat.size();
  vector<int> key;
  int r = 0;
  for (int col = 0; col < 2 * n; col++) {
    if (r == sz) {
      break;
    }
    for (int i = r; i < sz; i++) {
      if (mat[i][col]) {
        swap(mat[i], mat[r]);
        swap(R[i], R[r]);
        break;
      }
    }
    if (!mat[r][col]) {
      continue;
    }
    for (int i = r + 1; i < sz; i++) {
      if (mat[i][col]) {
        mat[i] ^= mat[r];
        R[i] ^= R[r];
      }
    }
    key.push_back(col);
    r += 1;
  }
  for (int i = r; i < sz; i++) {
    if (R[i] == 1) {
      cout << "NO" << '\n';
      return 0;
    }
  }
  cout << "YES" << '\n';
  vector<int> res(2 * n);
  for (int i = r - 1; i >= 0; i--) {
    res[key[i]] = R[i];
    if (R[i] == 1) {
      for (int j = i - 1; j >= 0; j--) {
        if (mat[j][key[i]]) {
          R[j] ^= 1;
        }
      }
    }
  }
  let[0] = '.';
  for (int i = 0; i < n; i++) {
    int num = res[2 * i + 0] + 2 * res[2 * i + 1];
    cout << let[num];
  }
  cout << '\n';
  return 0;
}