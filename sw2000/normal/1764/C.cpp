#include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using vi = vector<int>;
using vl = vector<ll>;
using oset = tree<int, null_type, less<int>, rb_tree_tag,
                  tree_order_statistics_node_update>;

// all type to_string for Debug
template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) { return '"' + s + '"'; }

string to_string(const char* s) { return to_string((string)s); }

string to_string(bool b) { return (b ? "true" : "false"); }

string to_string(vector<bool> v) {
  bool first = true;
  string ret = to_string(v.size()) + "^{";
  for (size_t i = 0; i < static_cast<size_t>(v.size()); i++) {
    if (!first) {
      ret += ", ";
    }
    first = false;
    ret += to_string(v[i]);
  }
  ret += "}";
  return ret;
}

template <size_t N>
string to_string(bitset<N> v) {
  string ret = "";
  for (size_t i = 0; i < N; i++) {
    ret += static_cast<char>('0' + v[i]);
  }
  return ret;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string ret = to_string(v.size()) + "^{";
  for (const auto& x : v) {
    if (!first) {
      ret += ", ";
    }
    first = false;
    ret += to_string(x);
  }
  ret += "}";
  return ret;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << "   END" << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << to_string(H);
  if (sizeof...(T)) cerr << ", ";
  debug_out(T...);
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }

template <class T>
void Min(T& a, const T b) {
  if (a > b) a = b;
}
template <class T>
void Max(T& a, const T b) {
  if (a < b) a = b;
}

#ifdef ONLINE_JUDGE
#define freopen(a, b, c)
#define D(...)
#else
#define D(...) \
  { cerr << "BEGIN   [" << #__VA_ARGS__ << "] -> ", debug_out(__VA_ARGS__); }
#endif
#define fi first
#define se second
#define endl '\n'
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr int inf = 0x3f3f3f3f;
constexpr int N = 5e5 + 10, M = 30;

ll solve() {
  int n;
  cin >> n;
  vi ar(n);
  for (auto& i : ar) {
    cin >> i;
  }
  sort(ar.begin(), ar.end());
  D(ar)
  if (ar.front() == ar.back()) {
    return n / 2;
  }
  ll ret = 0;
  for (int i = 1; i < n; i++) {
    if (ar[i] != ar[i - 1]) {
      Max(ret, 1ll * i * (n - i));
    }
  }
  return ret;
}
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  freopen("a.in", "r", stdin);
  int _ = 1;
  cin >> _;
  while (_--) {
    cout << (solve());
    cout << endl;
  }
}