#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <complex>
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
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
typedef vector<int> vi;
#define f first
#define s second
#define derr if(0) cerr
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> matrix;

void die() {
  cout << "0\n";
  exit(0);
}

void solve() {
  string s;
  cin >> s;
  deque<pair<char, int>> q;
  for(int i = 0; i < sz(s);) {
    int j = i+1;
    while(j < sz(s) && s[i] == s[j]) j++;
    q.eb(s[i], j-i);
    i = j;
  }
  if(sz(q)%2==0) die();
  while(sz(q) > 1) {
    if(q.front().f != q.back().f) die();
    if(q.front().s + q.back().s < 3) die();
    q.pop_front();
    q.pop_back();
  }
  if(q.back().s == 1) die();
  cout << ++q.back().s << "\n";
}

// what would chika do
// are there edge cases (N=1?)
// are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// integer overflow?
// DS reset properly between test cases
// are you doing geometry in floating points

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}