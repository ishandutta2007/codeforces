#include <bits/stdc++.h>

#define more_test_cases int t;cin >> t;for(int ti=1;ti<=t;ti++)

#define CONCAT_HELP(x, y) x##y
#define CONCAT(x, y) CONCAT_HELP(x,y)

#define ff3(a, b, c) for(int a = b; a < c; a ++)
#define fb3(a, b, c) for(int a = b; a > c; a --)
#define ffi(a, b, c) ff3(a,b,c+1)
#define fbi(a, b, c) fb3(a,b,c-1)
#define ff2(b, c) ff3(CONCAT(i, __LINE__), b,c)
#define ff1(c) ff2(0,c)
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define ff(...) GET_MACRO(__VA_ARGS__, ff3, ff2, ff1)(__VA_ARGS__)

#define vector_print(name) {cout << #name << endl; ff(CONCAT(i, __LINE__), 0, name.size()) {cout << name[CONCAT(i, __LINE__)] << endl;} }

#define DOUBLE_EQUAL(x, y) (fabs((x)-(y))<EPSILON)
#define DOUBLE_LESS(x, y) (x < y && !DOUBLE_EQUAL(x,y))
#define DOUBLE_GREATER(x, y) (x > y && !DOUBLE_EQUAL(x,y))
#define DOUBLE_LESS_EQUAL(x, y) !DOUBLE_GREATER(x,y)
#define DOUBLE_GREATER_EQUAL(x, y) !DOUBLE_LESS(x,y)

#define MODULO (1e9+7)

#define EPSILON (1e-7)

#define MOD 1000000007

#define CONTAINS(x, y) (x.find(y) != x.end())

using namespace std;

template<typename T, typename U>
istream &operator>>(istream &in, pair<T, U> &data) {
  in >> data.first >> data.second;
  return in;
}

template<typename T>
istream &operator>>(istream &in, vector<T> &vect) {
  for (unsigned i = 0; i < vect.size(); i++) {
    in >> vect[i];
  }
  return in;
}

namespace std {
template<>
struct hash<std::pair<int, int>> {
  inline size_t operator()(const std::pair<int, int> &v) const {
    std::hash<int> int_hasher;
    return int_hasher(v.first) ^ int_hasher(v.second);
  }
};

}

template<typename Out>
void Split(const std::string &s, char delim, Out result) {
  std::stringstream ss(s);
  std::string item;
  while (std::getline(ss, item, delim)) {
    *(result++) = item;
  }
}

std::vector<std::string> str_split(const std::string &s, char delim) {
  std::vector<std::string> elems;
  Split(s, delim, std::back_inserter(elems));
  return elems;
}

int main() {
  ios_base::sync_with_stdio(false);

  int n,m;
  cin >> n >> m;

  vector<int> a(n);
  cin >> a;

  struct truck {
      int s,f,c,r;
  };

  vector<truck> trucks(m);
  ff(i,0,m) {
    cin >> trucks[i].s >> trucks[i].f >> trucks[i].c >> trucks[i].r;
    trucks[i].s --;
    trucks[i].f --;
  }

  // starting town, ending town, k
  vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int>(n, -1)));

  for(int starti = n-1; starti >= 0; starti --) {
    // all starts separate

    // init will none cities removed from fuel stop
    dp[starti][starti][0] = 0;
    ff(endi,starti+1,n) {
      dp[starti][endi][0] = max(dp[starti][endi-1][0], a[endi]-a[endi-1]);
    }


    ff(k,1,n - starti - 2 + 1) {
      int currmid = starti + 1;
      int curr_k_left = 0;

      dp[starti][starti+1+k][k] = a[starti+1+k] - a[starti];

      ff(endi, starti + 1 + k+1, n) {

        while ( curr_k_left < k && endi - currmid + 1 - 2 > k - curr_k_left-1 && (a[currmid+1]- a[starti]) < dp[currmid][endi][k - curr_k_left]) {
          currmid ++;
          curr_k_left ++;
        }

        dp[starti][endi][k] = max(a[currmid] - a[starti], dp[currmid][endi][k-curr_k_left]);
      }
    }
  }

  long long minV = 0;

  ff(mi,0,m) {
    truck t = trucks[mi];

    int not_refuel = max(0,t.f-t.s+1-t.r-2);

    int min_max = dp[t.s][t.f][not_refuel];

    long long maxf = min_max;
    maxf *= t.c;

    minV = max(minV, maxf);
  }

  cout << minV << endl;



  return 0;
}