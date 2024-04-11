#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define RE(i,n) FOR(i,1,n)
#define R(i,n) REP(i,n)
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

template<class C> void mini(C&a4, C b4){a4=min(a4,b4);}
template<class C> void maxi(C&a4, C b4){a4=max(a4,b4);}

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA...a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1,a...);
}

template<class T> ostream&operator<<(ostream&os, vector<T> V) {
  os<<"[";
  for (auto v : V)os<<v<<",";
  return os << "]";
}
template<class L, class R> ostream&operator<<(ostream&os, pair<L,R> P) {
  return os<<"("<<P.st<<","<<P.nd<<")";
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  
  int N;
  cin >> N;
  
  int row = 0, col = 0;
  
  ++N;
  
  auto Out = [&]() {
    cout << (char)(col + 'a') << row + 1 << " "; --N;
  };
  
  Out();
  
  if (N <= 7 * 7) {
    int step = 1;
    while (N > 2) {
      col += step;
      if (col > 6 || col < 0) {
        col -= step;
        ++row;
        step = -step;
      }
      Out();
    }
    
    row = 7;
    Out();
    col = 7;
    Out();
  } else {
    for (int i = 1; i <= 7; ++i) {
      col = i; Out();
    }
    for (int i = 1; i <= 6; ++i) {
      row = i; Out();
    }
    --col; Out();
    row = 7; Out();
    for (int i = 5; i >= 1; --i) {
      row = i; Out();
    }
    
    int step = -1;
    while (N > 2) {
      col += step;
      if (col > 5 || col < 0) {
        col -= step;
        ++row;
        step = -step;
      }
      Out();
    }
    
    if (row < 7) { row = 7; } else { --col; }
    Out();
    col = 7;
    Out();
  }
  
  cout << "\n";
}