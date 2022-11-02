#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
typedef long long ll;
typedef pair<int,int> pii;
template<class T> void print(T & x){ cout << x; }
template<class T,class U> void print(pair<T,U> & p){cout << "("; print(p.first); cout << ", "; print(p.second); cout << ")"; }
template<class T> void print(vector<T> & v) {
  cout << "{";
  if (sz(v)) print(v[0]);
  for (int i = 1; i < sz(v); i++) cout << ", ", print(v[i]);
  cout << "}\n";
}
template<class T> void print(deque<T> & v) {
  cout << "{";
  if (sz(v)) print(v[0]);
  for (int i = 1; i < sz(v); i++) cout << ", ", print(v[i]);
  cout << "}\n";
}

const ll inf = LLONG_MAX;

ll divide(ll a, ll b) {
  return a / b - ((a ^ b) < 0 && a % b);
}
// for doubles, use inf = 1.0 / 0 and div(a, b) = a / b

// for non-increasing queries, use commented lines
struct line {
  ll a, b, r;
  // bool operator<(ll x) const {
  //   return r < x;
  // }
};

struct convex_hull : vector<line> {
  int p = 0;
  bool isect(line & x, line & y) {
    if (x.a == y.a)
      x.r = x.b > y.b ? inf : -inf;
    else
      x.r = divide(y.b - x.b, x.a - y.a);
    return x.r >= y.r;
  }
  // add the line a * x + b to the convex hull, added lines must have increasing slope
  void add(ll a, ll b) {
    line l = {a, b, inf};
    if (size() - p > 0 && isect(back(), l))
      return;
    while (size() - p > 1 && (--(--end()))->r >= back().r)
      pop_back(), isect(back(), l);
    push_back(l);
  }
  // query the maximal value at position x
  ll query(ll x) {
    while (x > at(p).r)
      p++;
    return at(p).a * x + at(p).b;
    // auto l = *lower_bound(begin(), end(), x);
    // return l.a * x + l.b;
  }
};

const int n = 90;
int INF = 1e8;

int N;
int dp[2][n][n*n]; // [shield%2][pos][num steps avail]
vector<int> A;
vector<convex_hull> C(3*n*n);

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  int cnt = 0;
  for(int i=0; i<N; i++){
    bool x;
    cin >> x;
    if(x)
      A.push_back(cnt);
    else
      cnt++;
  }
  INF = cnt*(cnt-1)/2;
  for(int i=0; i<=cnt; i++){
    for(int j=0; j<=N*(N-1)/2; j++){
      dp[1][i][j] = i*(i-1)/2;
    }
  }
  vector<int> bst(N*(N-1)/2+1, INF);
  for(int sh=0; sh<sz(A); sh++){
    for(int i=0; i<sz(C); i++)
      C[i] = convex_hull();
    for(int pos=0; pos<=cnt; pos++){
      for(int step=0; step<=N*(N-1)/2; step++){
        int qi = step+abs(A[sh]-pos);
        int slope = 2*pos+1;
        int off = -(dp[(sh&1)^1][pos][step]*2 + pos*(pos+1));
        C[qi].add(slope, off);
        dp[sh&1][pos][step] = INF;
        if(sz(C[step])){
          //int v0 = getVal(sh, pos, step, 0);
          dp[sh&1][pos][step] = (-C[step].query(pos) + pos*pos)/2;
        }
      }
    }
    for(int step=0; step<=N*(N-1)/2; step++){
      bst[step] = min(bst[step], dp[sh&1][cnt][step]);
    }
  }
  cnt = cnt*(cnt-1)/2;
  for(int j=0; j<=N*(N-1)/2; j++){
    cout << max(0, cnt - bst[j]) << " ";
  }
  cout << endl;
}