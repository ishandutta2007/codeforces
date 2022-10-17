#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef long long H;
static const H M = INT_MAX;
static H C; // initialized below

// Arithmetic mod M. "typedef H K;" instead if you think
// test data is random. (Haha, good luck.)
struct K {
  H x; K(H x=0) : x(x) {}
  K operator+(K o) { H y = x + o.x; return y - (y >= M) * M; }
  K operator*(K o) { return x*o.x % M; }
  H operator-(K o) { H y = x - o.x; return y + (y < 0) * M; }
};

struct HashInterval {
  vector<K> ha, pw;
  HashInterval(string& str) : ha(sz(str)+1), pw(ha) {
    pw[0] = 1;
    rep(i,0,sz(str))
      ha[i+1] = ha[i] * C + str[i],
      pw[i+1] = pw[i] * C;
  }
  H hashInterval(int a, int b) { // hash [a, b)
    return ha[b] - ha[a] * pw[b - a];
  }
};

H hashString(string& s) {
  K h = 0;
  trav(c, s) h = h * C + c;
  return h - 0;
}

int main(){
  timeval tp;
  gettimeofday(&tp, 0);
  C = tp.tv_usec;
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  int n,k;
  string t;
  cin>>n>>t>>k;
  vector<string> words(k);
  map<int, unordered_map<H, int>> hs;
  rep(i,0,k) {
    string s;
    cin>>s;
    words[i] = s;
    for(char &c : s) c = tolower(c);
    reverse(all(s));
    H h = hashString(s);
    hs[s.size()][h] = i;
  }
  HashInterval hi(t);
  vi works(n+1, -1);
  works[0] = -2;
  rep(b,1,n+1) {
    for(auto &[len, lookup] : hs) {
      int a = b-len;
      if(a < 0) continue;
      if(works[a] == -1) continue;
      H h = hi.hashInterval(a,b);
      auto it = lookup.find(h);
      if(it == lookup.end()) continue;
      works[b] = it->second;
    }
  }
  assert(works[n] != -1);
  deque<int> d;
  for(int p = n; p != 0; p -= words[works[p]].size())
    d.push_front(works[p]);

  for(int i:d) cout << words[i] << " ";
  cout << endl;
  return 0;
}