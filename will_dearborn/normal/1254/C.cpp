#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<double, double> pdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
//const int mod = ;
typedef pii pt;

bool cmp (pt a, pt b) {
	return a.first < b.first || (a.first == b.first && a.second < b.second);
}

bool cw (pt a, pt b, pt c) {
	return a.first*(b.second-c.second)+b.first*(c.second-a.second)+c.first*(a.second-b.second) < 0;
}

bool ccw (pt a, pt b, pt c) {
	return a.first*(b.second-c.second)+b.first*(c.second-a.second)+c.first*(a.second-b.second) > 0;
}

void convex_hull (vector<pt> & a) {
	if (a.size() == 1)  return;
	sort (a.begin(), a.end(), &cmp);
	pt p1 = a[0],  p2 = a.back();
	vector<pt> up, down;
	up.push_back (p1);
	down.push_back (p1);
	for (size_t i=1; i<a.size(); ++i) {
		if (i==a.size()-1 || cw (p1, a[i], p2)) {
			while (up.size()>=2 && !cw (up[up.size()-2], up[up.size()-1], a[i]))
				up.pop_back();
			up.push_back (a[i]);
		}
		if (i==a.size()-1 || ccw (p1, a[i], p2)) {
			while (down.size()>=2 && !ccw (down[down.size()-2], down[down.size()-1], a[i]))
				down.pop_back();
			down.push_back (a[i]);
		}
	}
	a.clear();
	for (size_t i=0; i<up.size(); ++i)
		a.push_back (up[i]);
	for (size_t i=down.size()-2; i>0; --i)
		a.push_back (down[i]);
}

int Q = 0;
int n;

const int DEBUG = 0;
vii p;

pii sub(pii a, pii b) {
  return pii(b.first - a.first, b.second - a.second);
}

ll vect(pii a, pii b) {
  return a.first * b.second - a.second * b.first;
}

ll area(int i, int j, int k) {
  ++Q;
  assert(Q <= 3 * n);
  cout << 1 << ' ' << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
  ll s;
  if (!DEBUG) cin >> s;
  else s = abs(vect(sub(p[j], p[i]), sub(p[k], p[i])));
  return s;
}

ll sign(int i, int j, int k) {
  ++Q;
  assert(Q <= 3 * n);
  cout << 2 << ' ' << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
  ll s;
  if (!DEBUG) cin >> s;
  else s = vect(sub(p[j], p[i]), sub(p[k], p[i])) > 0 ? 1 : -1;
  return s;
}

const int MAX = 1000;

void solve() {
  Q = 0;
  if (!DEBUG) cin >> n;
  else {
    n = 1000;
    p.clear();
    for (int i = 0; i < n; ++i) {
      p.push_back(pii(rand() % MAX, rand() % MAX));
    }
    convex_hull(p);
    n = p.size();
    if (n < 3) return;
    random_shuffle(p.begin(), p.end());
    for (int i = 0; i < n; ++i) {
      cerr << p[i].first << ' ' << p[i].second << endl;
    }
  }
  int cand = 1;
  for (int i = 2; i < n; ++i) {
    if (sign(0, cand, i) < 0) cand = i;
  }
  vi v = {0, cand};
  vl s = {0, 0};
  vi ord;
  for (int i = 1; i < n; ++i) if (i != cand) ord.push_back(i);
  random_shuffle(ord.begin(), ord.end());
  for (int i : ord) {
//    cerr << "i: " << i << endl;
    ll ns = area(0, cand, i);
    if (v.size() == 2) {
      v.push_back(i);
      s.push_back(ns);
      continue;
    }
    int prsz = v.size();
    for (int j = 1; j < (int)v.size(); ++j) {
      int nj = (j + 1) % v.size();
      int pj = j - 1;
      if (ns > s[j] && ns < s[nj] && sign(v[j], v[nj], i) < 0) {
        v.insert(v.begin() + j + 1, i);
        s.insert(s.begin() + j + 1, ns);
        break;
      }
      if (ns < s[j] && ns > s[nj]) {
        v.insert(v.begin() + j + 1, i);
        s.insert(s.begin() + j + 1, ns);
        break;
      }
      if (s[j] == s[nj] && ns > s[j] && sign(v[j], v[nj], i) < 0) {
        v.insert(v.begin() + j + 1, i);
        s.insert(s.begin() + j + 1, ns);
        break;
      }
      if (s[j] > s[nj] && s[j] > s[pj] && ns >= s[j]) {
        if (sign(v[j], v[nj], i) < 0) {
          v.insert(v.begin() + j + 1, i);
          s.insert(s.begin() + j + 1, ns);
        } else {
          v.insert(v.begin() + j, i);
          s.insert(s.begin() + j, ns);
        }
        break;
      }
    }
    assert(v.size() > prsz);
  }
  if (DEBUG) {
    Q = 0;
    for (int i = 0; i < n; ++i) {
      int pr = (i + n - 1) % n, nx = (i + 1) % n;
      assert(sign(v[pr], v[i], v[nx]) > 0);
    }
  }
  cout << 0 << ' ';
  for (int i = 0; i < n; ++i) cout << v[i] + 1 << ' ';
  cout << endl;
}

int main() {
  srand(131);
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  for (int i = 0; i <= DEBUG * 1000; ++i) solve();
  return 0;
}