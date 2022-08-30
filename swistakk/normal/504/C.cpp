#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define int long long
#define st first
#define nd second
#define rd third
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define RE(i, n) FOR(i, 1, n)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#ifdef LOCAL
#define debug(x) {cerr <<#x<<" = " <<x<<"\n"; }
#define debug2(x, y) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<"\n";}
#define debug3(x, y, z) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<"\n";}
#define debug4(x, y, z, t) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<", "<<#t <<" = " <<t<<"\n";}
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
#else
#define debug(x)
#define debug2(x, y)
#define debug3(x, y, z)
#define debug4(x,y,z,t)
#define debugv(x)
#define cerr if(0)cout
#endif
#define make(type, x) type x; cin>>x;
#define make2(type, x, y) type x, y; cin>>x>>y;
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z;
#define make4(type, x, y, z, t) type x, y, z, t; cin>>x>>y>>z>>t;
#define next ____next
#define prev ____prev
#define left ____left
#define hash ____hash
using namespace std;
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
template<class A, class B, class C> struct Triple { A first; B second; C third; };
template<class T> void ResizeVec(T&, vector<int>) {}
template<class T> void ResizeVec(vector<T>& vec, vector<int> sz) {
  vec.resize(sz[0]); sz.erase(sz.begin()); if (sz.empty()) { return; }
  for (T& v : vec) { ResizeVec(v, sz); }
}

const int N = 1e5 + 5;
int t[N];
int cnt_all[N];
int need[N];
int bad[N];
int has_from_pair[N];
int belong[N];
int need_val[N];
int good;
int n;
int bad_cnt;
int bad_outside;
void Update(int val, int delta) {
  int badd = -(need_val[val] > 0);
  need_val[val] += delta;
  badd += (need_val[val] > 0);
  bad_cnt += badd;
  good = (bad_cnt == 0 && bad_outside == 0);
}
void Add(int pos) {
  int para = belong[pos];
  has_from_pair[para]++;
  Update(t[pos], -1);
  int nei = n - pos + 1;
  if (has_from_pair[para] == 2) {
    Update(t[pos], -1);
    //need[t[nei]]--;
  } else {
    if (pos == n / 2 + 1 && n % 2 == 1) { goto A; }
    if (bad[para]) { bad_outside--; }
    Update(t[nei], 1);
    A: ;
  }
//   cerr<<"Added "<<pos<<endl;
//   RE (i, n) {
//     cerr<<need_val[i]<<" ";
//   }
//   cerr<<endl;
//   debug2(bad_cnt, bad_outside);
}
void Subtract(int pos) {
  int para = belong[pos];
  has_from_pair[para]--;
  Update(t[pos], 1);
  int nei = n - pos + 1;
  if (has_from_pair[para] == 0) {
    if (pos == n / 2 + 1 && n % 2 == 1) { goto A; }
    if (bad[para]) { bad_outside++; }
    Update(t[nei], -1);
    A: ;
  } else {
    Update(t[pos], 1);
  }
//   cerr<<"Subtracted "<<pos<<endl;
//   RE (i, n) {
//     cerr<<need_val[i]<<" ";
//   }
//   cerr<<endl;
//   debug2(bad_cnt, bad_outside);
}
  
  
  
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  cin>>n;
  RE (i, n) {
    cin>>t[i];
    cnt_all[t[i]]++;
    belong[i] = min(i, n - i + 1);
  }
  int odd = 0;
  RE (i, n) {
    odd += cnt_all[i] % 2;
  }
  if (odd >= 2) {
    cout<<0<<"\n";
    return 0;
  }
  RE (i, n / 2) {
    if (t[i] != t[n - i + 1]) {
      bad[i] = 1;
      bad_cnt++;
    }
  }
  if (bad_cnt == 0) {
    cout<<n * (n + 1) / 2 << endl;
    return 0;
  }
  bad_outside = bad_cnt;
  bad_cnt = 0;
  good = 0;
  int res = 0;
  int last = 0;
  RE (i, n) {
    if (last < i) {
      Add(i);
      last = i;
    }
    while (!good && last < n) {
      last++;
      Add(last);
    }
    if (good) {
      res += n - last + 1;
      debug2(i, last);
    }
    Subtract(i);
  }
  cout<<res<<"\n";
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}