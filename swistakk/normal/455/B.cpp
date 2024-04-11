#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <utility>
#include <iomanip>
#include <assert.h>
#define MP make_pair
#define PB push_back
#define int long long
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define RE(i, n) FOR(i, 1, n)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#ifdef LOCAL
#define debug(x) {cerr <<#x <<" = " <<x <<"\n"; }
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
#else
#define debug(x)
#define debugv(x)
#endif
#define make(type, x) type x; cin>>x;
#define make2(type, x, y) type x, y; cin>>x>>y;
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z;
using std::endl;
using std::cout;
using std::cin;
using std::cerr;
using std::vector;
using std::set;
using std::map;
using std::pair;
using std::max;
using std::min;
using std::ostream;
using std::fixed;
using std::ios_base;
using std::setprecision;
using std::make_pair;
using std::string;
using std::multiset;
using std::next_permutation;
using std::prev_permutation;
using std::random_shuffle;
using std::greater;
using std::lower_bound;
using std::upper_bound;
typedef long long ll;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VLL;
typedef vector<pair<int, int> > VPII;
typedef vector<pair<ll, ll> > VPLL;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.first << ", " << pair.second << ")";}

const int kEven = 0, kOdd = 1, kFirstDecides = 2, kSecondDecides = 3;

struct Trie {
  int st;
  Trie() {
    REP (i, 30) {
      sons[i] = nullptr;
    }
    st = kEven;
  }
  Trie* sons[30];
  ll Dfs();
  void ins(string& s, int dep) {
    //cerr<<"ins\n";
    if (dep == s.length()) {
      return;
    }
    int which_son = s[dep] - (int)('a');
    if (sons[which_son] == nullptr) {
      sons[which_son] = new Trie();
      //cerr<<"Create\n";
    }
    sons[which_son]->ins(s, dep + 1);
  }
};
int vis;
ll Trie::Dfs() {
  vis++;
  int cnt[4] = {};
  for (int i = 0; i < 30; i++) {
    if (sons[i] != nullptr) {
      sons[i]->Dfs();
      cnt[sons[i]->st]++;
    }
  }
  if (cnt[kSecondDecides]) {
    st = kFirstDecides;
  } else if (cnt[kOdd] && cnt[kEven]) {
    st = kFirstDecides;
  } else if (cnt[kOdd]) {
    st = kEven;
  } else if (cnt[kEven]) {
    st = kOdd;
  } else if (cnt[kFirstDecides]) {
    st = kSecondDecides;
  } else {
    st = kEven;
  }
  //cerr<<st<<"\n";
}


#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make2(int, n, k);
  string nic;
  getline(cin, nic);
  Trie* root = new Trie();
  RE (i, n) {
    getline(cin, nic);
    root->ins(nic, 0);
    //debug(str[i]);
  }
  root->Dfs();
  debug(vis);
  debug(root->st);
  if (root->st == kFirstDecides) {
    cout<<"First\n";
  } else if (root->st == kSecondDecides || root->st == kEven) {
    cout<<"Second\n";
  } else if (k % 2 == 0) {
    cout<<"Second\n";
  } else {
    cout<<"First\n";
  }
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}