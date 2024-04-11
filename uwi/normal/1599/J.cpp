#line 2 "/home/maspy/library/my_template.hpp"
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;
using vi = vector<ll>;
template <class T> using vc = vector<T>;
template <class T> using vvc = vector<vc<T>>;
template <class T> using vvvc = vector<vvc<T>>;
template <class T> using vvvvc = vector<vvvc<T>>;
template <class T> using vvvvvc = vector<vvvvc<T>>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

#define vec(type, name, ...) vector<type> name(__VA_ARGS__)
#define VEC(type, name, size)                                                                                                                                  \
    vector<type> name(size);                                                                                                                                   \
    IN(name)
#define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define VV(type, name, h, w)                                                                                                                                   \
    vector<vector<type>> name(h, vector<type>(w));                                                                                                             \
    IN(name)
#define vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...)                                                                                                                         \
    vector<vector<vector<vector<type>>>> name(a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))

#define FOR(i, n) for (ll i = 0; (i) < (ll)(n); ++(i))
#define FOR3(i, m, n) for (ll i = (m); (i) < (ll)(n); ++(i))
#define FOR_R(i, n) for (ll i = (ll)(n)-1; (i) >= 0; --(i))
#define FOR3_R(i, m, n) for (ll i = (ll)(n)-1; (i) >= (ll)(m); --(i))
#define FORIN(x, A) for (auto&& x : A)
#define FOR_nCk(s, n, k) \
  for (ll s = (1 << k) - 1, tmp_var = 0; s < (1 << n); \
  tmp_var = s | (s - 1), s = (tmp_var + 1) | (((~tmp_var & -~tmp_var) - 1) >> (__builtin_ctz(s) + 1))) 
#define all(x) x.begin(), x.end()

#define elif else if

#define popcnt __builtin_popcount

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second

#define SUM(v) accumulate(all(v), 0LL)
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))

#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())

template <class T> T ceil(T x, T y) {
    assert(y >= 1);
    return (x > 0 ? (x + y - 1) / y : x / y);
}

template <class T> T floor(T x, T y) {
    assert(y >= 1);
    return (x > 0 ? x / y : (x - y + 1) / y);
}

#define INT(...) \
  int __VA_ARGS__; \
  IN(__VA_ARGS__)
#define LL(...) \
  ll __VA_ARGS__; \
  IN(__VA_ARGS__)
#define STR(...) \
  string __VA_ARGS__; \
  IN(__VA_ARGS__)
#define CHR(...) \
  char __VA_ARGS__; \
  IN(__VA_ARGS__)
#define DBL(...) \
  long double __VA_ARGS__; \
  IN(__VA_ARGS__)
void scan(int &a) { cin >> a; }
void scan(long long &a) { cin >> a; }
void scan(char &a) { cin >> a; }
void scan(double &a) { cin >> a; }
void scan(long double &a) { cin >> a; }
void scan(string &a) { cin >> a; }
template <class T, class S> void scan(pair<T, S> &p) { scan(p.first), scan(p.second); }
template <class T> void scan(vector<T> &a) {for(auto &i : a) scan(i);}
template <class T> void scan(T &a) { cin >> a; }
void IN() {}
template <class Head, class... Tail> void IN(Head &head, Tail &...tail) {
  scan(head);
  IN(tail...);
}

vi s_to_vi(string S, char first_char='a'){
  vi A(S.size());
  FOR(i, S.size()){
    A[i] = S[i] - first_char;
  }
  return A;
}

template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& A) {
  os << A.fi << " " << A.se;
  return os;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& A) {
  for (size_t i = 0; i < A.size(); i++) {
    if(i) os << " ";
    os << A[i];
  }
  return os;
}

void print() {
  cout << "\n";
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
  cout << head;
  if (sizeof...(Tail)) cout << " ";
  print(forward<Tail>(tail)...);
}

const string YESNO[2] = {"NO", "YES"};
const string YesNo[2] = {"No", "Yes"};
const string yesno[2] = {"no", "yes"};
void YES(bool t = 1) { cout << YESNO[t] << endl; }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { cout << YesNo[t] << endl; }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { cout << yesno[t] << endl; }
void no(bool t = 1) { yes(!t); }

template <typename T>
vector<T> cumsum(vector<T> A) {
  ll N = A.size();
  vector<T> B(N + 1);
  B[0] = T(0);
  FOR(i, N) { B[i + 1] = B[i] + A[i]; }
  return B;
}

vi bin_count(vi& A, ll size) {
  vi C(size);
  for (auto&& x : A) {
    ++C[x];
  }
  return C;
}

template <typename T>
vi argsort(vector<T>& A){
  vi ids(A.size());
  iota(all(ids), 0);
  sort(all(ids), [&](ll i, ll j){
    return A[i] < A[j] || (A[i] == A[j] && i < j);
  });
  return ids;
}

ll binary_search(function<bool(ll)> check, ll ok, ll ng) {
  while (abs(ok - ng) > 1) {
    auto x = (ng + ok) / 2;
    if (check(x))
      ok = x;
    else
      ng = x;
  }
  return ok;
}

template <class T, class S> inline bool chmax(T &a, const S &b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S> inline bool chmin(T &a, const S &b) { return (a > b ? a = b, 1 : 0); }
#line 2 "main.cpp"

void solve() {
  LL(N);
  VEC(ll, B, N);

  if (N == 2) {
    ll a = B[0], b = B[1];
    if (a != b) return NO();
    YES();
    print(0, a);
    return;
  }

  UNIQUE(B);
  if (B.size() < N) {
    vi ANS = B;
    while (ANS.size() < N) ANS.eb(0);
    YES();
    print(ANS);
    return;
  }

  assert(B.size() == N);

  if (N == 3) {
    ll S = SUM(B);
    if (S % 2 != 0) return NO();
    S /= 2;
    YES();
    vi ANS = {S - B[0], S - B[1], S - B[2]};
    print(ANS);
    return;
  }

  vi EV, OD;
  FORIN(x, B) {
    if (x % 2 == 0)
      EV.eb(x);
    else
      OD.eb(x);
  }

  if (EV.size() >= 3) {
    ll a = EV[0], b = EV[1], c = EV[2];
    ll S = (a + b + c) / 2;
    vi ANS = {S - a, S - b, S - c};
    FOR3(i, 3, EV.size()) ANS.eb(EV[i] - ANS[0]);
    FOR(i, OD.size()) ANS.eb(OD[i] - ANS[0]);
    assert(ANS.size() == N);
    YES();
    return print(ANS);
  }

  if (OD.size() >= 2 && EV.size() >= 1) {
    ll a = OD[0], b = OD[1], c = EV[0];
    ll S = (a + b + c) / 2;
    vi ANS = {S - a, S - b, S - c};
    FOR3(i, 1, EV.size()) ANS.eb(EV[i] - ANS[0]);
    FOR3(i, 2, OD.size()) ANS.eb(OD[i] - ANS[0]);
    YES();
    return print(ANS);
  }

  assert(EV.size() == 0);

  ll K = min(N, 24LL);
  vi DP(1 << K);
  FOR(k, K) FOR(s, 1 << k) DP[s + (1 << k)] = DP[s] + B[k];
  pi st = [&]() -> pi {
    vc<map<ll, ll>> MEMO(K + 1);
    FOR(s, 1 << K) {
      ll n = popcnt(s);
      if (MEMO[n].count(DP[s])) {
        ll t = MEMO[n][DP[s]];
        return mp(s, t);
      }
      MEMO[n][DP[s]] = s;
    }
    return mp(-1, -1);
  }();

  ll s = st.fi, t = st.se;
  if (s == -1) return NO();
  ll u = s & t;
  s -= u, t -= u;
  assert(popcnt(s) == popcnt(t));
  assert(DP[s] == DP[t]);
  assert((s & t) == 0);
  vi X, Y, Z;
  FOR(k, K) {
    if (s & 1 << k) X.eb(B[k]);
    elif (t & 1 << k) Y.eb(B[k]);
    else Z.eb(B[k]);
  }
  FOR3(k, K, B.size()) Z.eb(B[k]);
  assert(X.size() == Y.size());

  vi ANS = {0};
  FOR(i, X.size()) {
    ANS.eb(X[i] - ANS.back());
    ANS.eb(Y[i] - ANS.back());
  }
  assert(ANS.back() == 0);
  ANS.pop_back();
  FORIN(x, Z) ANS.eb(x);
  YES();
  print(ANS);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}