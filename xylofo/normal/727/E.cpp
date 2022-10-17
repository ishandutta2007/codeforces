#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.)end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


typedef long long H;
static const H M1 = INT_MAX;
static const H M2 = INT_MAX-12;
static H C;

template<const H M>
struct K {
  H x; K(H x=0) : x(x) {}
  K operator+(K o) { H y = x + o.x; return y - (y >= M) * M; }
  K operator*(K o) { return x*o.x % M; }
  H operator-(K o) { H y = x - o.x; return y + (y < 0) * M; }
};

template<const H M>
vector<H> getHashes(const string& str, int length) {
  if (sz(str) < length) return {};
  K<M> h = 0, pw = 1;
  rep(i,0,length)
    h = h * C + str[i], pw = pw * C;
  vector<H> ret = {h - 0};
  ret.reserve(sz(str) - length + 1);
  rep(i,length,sz(str)) {
    ret.push_back(h * C + str[i] - pw * str[i-length]);
    h = ret.back();
  }
  return ret;
}

template<const H M>
H hashString(string& s) {
  K<M> h = 0;
  trav(c, s) h = h * C + c;
  return h - 0;
}

void bad(){
  cout << "NO" << endl;
  exit(0);
}
int main() {
  timeval tp;
  gettimeofday(&tp, 0);
  C = tp.tv_usec;
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  int n, k, m;
  cin>>n>>k;
  n = n*k;
  string s;
  cin>>s;
  cin>>m;
  vector<string> ss(m);
  vector<H> hs1 = getHashes<M1>(s+s, k), hk1(m);
  vector<H> hs2 = getHashes<M2>(s+s, k), hk2(m);
  vector<H> hs(sz(hs1)), hk(m);
  rep(i,0,sz(hs)) hs[i] = hs1[i] ^ (hs2[i]<<32);
  rep(i,0,m) {
    cin>>ss[i];
    hk1[i] = hashString<M1>(ss[i]);
    hk2[i] = hashString<M2>(ss[i]);
    hk[i] = hk1[i] ^ (hk2[i] << 32);
  }
  rep(off,0,k) {
    multimap<H, int> S;
    rep(i,0,m) S.emplace(hk[i], i+1);
    vi idx;
    for(int i = off; i < n; i += k) {
      auto it = S.find(hs[i]);
      if(it == S.end()) goto badd;
      idx.push_back(it->second);
      S.erase(it);
    }
    cout << "YES" << endl;
    for(int i : idx) cout << i << " ";
    cout << endl;
    exit(0);
badd:;
  }
  bad();
}