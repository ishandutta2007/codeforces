#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using vi = vector<int>;
using vl = vector<ll>;

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

bool solve() {
  int n, k;
  cin >> n >> k;
  vi ar(n), br(n);
  for (int i = 0; i < n; i++) {
    cin >> ar[i] >> br[i];
  }
  if (ar[0] + br[0] < k) {
    return false;
  }
  if (ar[0] >= k) {
    return true;
  }
  k -= br[0];

  vi rk(n - 1);
  iota(rk.begin(), rk.end(), 1);
  sort(rk.begin(), rk.end(),
       [&](int a, int b) { return ar[a] + br[a] > ar[b] + br[b]; });

  auto cmp=[&](int a,int b){return ar[a]-br[a]>ar[b]-br[b];};
  priority_queue<int,vi, decltype(cmp)>q(cmp);
  for (auto i : rk) {
    if (ar[i] + br[i] >= k) {
      q.emplace(i);
    } else {
      while (!q.empty()) {
        int j = q.top();
        q.pop();
        if (ar[j] >= k) {
          return true;
        }
        k -= br[j];
        if (ar[i] + br[i] >= k) {
          q.emplace(i);
          break;
        }
      }
    }
  }

  while (!q.empty()) {
    int j = q.top();
    q.pop();
    if (ar[j] >= k) {
      return true;
    }
    k -= br[j];
  }
  return false;
}
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  freopen("a.in", "r", stdin);
  int _ = 1;
  cin >> _;
  while (_--) {
    cout << (solve() ? "Yes" : "No");
    cout << endl;
  }
}