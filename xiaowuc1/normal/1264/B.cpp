#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

// BEGIN NO SAD
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef vector<int> vi;
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void die() {
  cout << "NO\n";
  exit(0);
}

void win(vector<int>& v) {
  cout << "YES\n";
  for(int i = 0; i < sz(v); i++) {
    if(i) cout << " "; cout << v[i];
  } cout << "\n";
  exit(0);
}

void dfs(int a, int b, int c, vector<int>& v) {
  if(a+b+c==0) win(v);
  if(abs(v.back()-0) == 1 && a > 0) {
    v.push_back(0);
    dfs(a-1, b, c, v);
    v.pop_back();
  }
  if(abs(v.back()-1) == 1 && b > 0) {
    v.push_back(1);
    dfs(a, b-1, c, v);
    v.pop_back();
  }
  if(abs(v.back()-2) == 1 && c > 0) {
    v.push_back(2);
    dfs(a, b, c-1, v);
    v.pop_back();
  }
}

void solve(int a, int b, int c, int d, int s) {
  if(s == 0 && a == 0) return;
  if(s == 1 && b == 0) return;
  if(s == 2 && c == 0) return;
  if(s == 3 && d == 0) return;
  vector<int> v;
  v.push_back(s);
  if(s == 0) a--;
  if(s == 1) b--;
  if(s == 2) c--;
  if(s == 3) d--;
  // clear out the d
  if(v.back() == 0) {
    if(b == 0) return;
    b--; v.push_back(1);
  }
  if(v.back() == 1) {
    if(c == 0) return;
    c--; v.push_back(2);
  }
  if(v.back() == 3) {
    if(c == 0) return;
    c--; v.push_back(2);
  }
  assert(v.back() == 2);
  while(d > 0) {
    if(c == 0) return;
    d--; v.push_back(3);
    c--; v.push_back(2);
  }
  assert(d == 0);
  while(c > 1) {
    if(b == 0) return;
    b--; v.push_back(1);
    c--; v.push_back(2);
  }
  while(a > 1) {
    if(b == 0) return;
    b--; v.push_back(1);
    a--; v.push_back(0);
  }
  dfs(a, b, c, v);
}

void solveTwo(int a, int aa, int b, int ba) {
  if(abs(aa-ba) > 1) return;
  if(aa < ba) {
    swap(a,b);
    swap(aa,ba);
  }
  vector<int> v;
  while(aa > 0 || ba > 0) {
    v.push_back(a); aa--;
    if(ba) {
      ba--;
      v.push_back(b);
    }
  }
  win(v);
}

void solve() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int uniq = 0;
  int amt = 0;
  uniq += min(a, 1); amt += a;
  uniq += min(b, 1); amt += b;
  uniq += min(c, 1); amt += c;
  uniq += min(d, 1); amt += d;
  if(uniq == 1) {
    if(amt > 1) die();
    vector<int> v;
    if(a) v.push_back(0);
    if(b) v.push_back(1);
    if(c) v.push_back(2);
    if(d) v.push_back(3);
    win(v);
    return;
  }
  if(uniq == 2) {
    if(a && c) die();
    if(a && d) die();
    if(b && d) die();
    if(a && b) solveTwo(0,a,1,b);
    if(b && c) solveTwo(1,b,2,c);
    if(c && d) solveTwo(2,c,3,d);
    die();
  }
  if(b == 0) die();
  solve(a,b,c,d,0);
  solve(a,b,c,d,1);
  solve(a,b,c,d,2);
  solve(a,b,c,d,3);
  die();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}