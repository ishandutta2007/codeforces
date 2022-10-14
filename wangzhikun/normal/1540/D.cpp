/**
 *    author:  tourist
 *    created: 25.06.2021 19:43:15       
**/
#undef _GLIBCXX_DEBUG

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

#define sz(s) ((int) s.size())

// https://github.com/kth-competitive-programming/kactl/blob/main/content/data-structures/FenwickTree.h

struct FT {
	vector<int> s;
	FT(int n) : s(n) {}
	void update(int pos, int dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	int query(int pos) { // sum of values in [0, pos)
		int res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	int lower_bound(int sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 19; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  const int BLOCK = max(1, (int) sqrt(0.2 * n));
  const int cnt = (n + BLOCK - 1) / BLOCK;
  vector<int> L(cnt);
  vector<int> R(cnt);
  vector<vector<int>> app(cnt);
  FT fenw(n + 1);
  for (int i = 1; i <= n; i++) {
    fenw.update(i, +1);
  }
  auto Build = [&](int bid) {
    for (int j = L[bid]; j < R[bid]; j++) {
      int& val = app[bid][j - L[bid]];
      val = max(0, fenw.lower_bound(b[j]));
//      debug(bid, j, val);
      fenw.update(val, +1);
    }
    for (int j = L[bid]; j < R[bid]; j++) {
      int& val = app[bid][j - L[bid]];
      fenw.update(val, -1);
    }
    sort(app[bid].begin(), app[bid].end());
//    debug(bid, b, app[bid]);
  };
  for (int i = 0; i < cnt; i++) {
    L[i] = i * BLOCK;
    R[i] = min(n, (i + 1) * BLOCK);
    app[i].resize(R[i] - L[i]);
    Build(i);
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int op;
    cin >> op;
    if (op == 1) {
      int i, x;
      cin >> i >> x;
      --i;
      b[i] = x;
      Build(i / BLOCK);
    } else {
      int i;
      cin >> i;
      --i;
      int bid = i / BLOCK;
      int res = b[i];
      for (int j = i + 1; j < R[bid]; j++) {
        res += (res >= b[j]);
      }
      for (int k = bid + 1; k < cnt; k++) {
        res += (int) (upper_bound(app[k].begin(), app[k].end(), res) - app[k].begin());
      }
      cout << n - res << '\n';
    }
  }
  debug(clock());
  return 0;
}