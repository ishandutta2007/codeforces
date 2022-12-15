//testing


#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <chrono>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10, P = sqrt(N / 2);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<int> a;
int imp;

void make_move(vector<int>& a, int imp);
int query(int i);

int main() {
  fast_cin();
  int n, k;
  cin >> n >> k;
  // imp = uniform_int_distribution<int>(0, n - 1)(rng);
  // a.resize(n, k);
  int p = -1, pval;
  while (p == -1) {
    int i = uniform_int_distribution<int>(0, n - 1)(rng);
    int val = query(i);
    if (val != k) {
      p = i;
      pval = val;
      break;
    }
  }
  while (pval < k) {
    p = (p + 1) % n;
    pval = query(p);
  }
  while (pval > k) {
    p = (p + n - 1) % n;
    pval = query(p);
  }
  cout << "! " << (p + 1) << endl;
  // cout << imp + 1 << endl;
}

int query(int i) {
  cout << "? " << (i + 1) << endl;
  // int ans = a[i];
  // make_move(a, imp);
  // return ans;
  int ans; cin >> ans;
  return ans;
}

void make_move(vector<int>& a, int imp) {
  int n = a.size();
  vector<int> b(n, 0);
  for (int i = 0; i < n; ++i) {
    if (i != imp) {
      b[(i + n - 1) % n] += a[i] / 2;
      b[(i + 1) % n] += a[i] - a[i] / 2;
    } else {
      b[(i + 1) % n] += a[i];
    }
  }
  a = b;
}