#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) //ignore
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;


//mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng(42);

const bool DEB = false;

set<pii>::iterator addInterval(set<pii>& is, int L, int R) {
  if (L == R) return is.end();
  auto it = is.lower_bound({L, R}), before = it;
  while (it != is.end() && it->first <= R) {
    R = max(R, it->second);
    before = it = is.erase(it);
  }
  if (it != is.begin() && (--it)->second >= L) {
    L = min(L, it->first);
    R = max(R, it->second);
    is.erase(it);
  }
  return is.insert(before, {L,R});
}

void removeInterval(set<pii>& is, int L, int R) {
  if (L == R) return;
  auto it = addInterval(is, L, R);
  auto r2 = it->second;
  if (it->first == L) is.erase(it);
  else (int&)it->second = L;
  if (R != r2) is.emplace(R, r2);
}

int main() {
  const int B = 1e8;
  uniform_int_distribution<int> uid(-B,B);

  set<int> _ver, _hor;
  if(DEB) {
    int n = 1e4, m = 1e4;
    //rep(i,0,n) _ver.emplace(rng()%(2*B)-B);
    //rep(i,0,m) _hor.emplace(rng()%(2*B)-B);
    rep(i,0,n) _ver.emplace(i);
    rep(i,0,m) _hor.emplace(i);
    //debug(_ver);
    //debug(_hor);
    //debug('%')
  }

  auto close = [&](int t, const auto&s) {
    auto it = s.lower_bound(t);
    int d = 1e9;
    if(it != end(s)) d = min(d, abs(t-*it));
    if(it != begin(s)) d = min(d, abs(t-*prev(it)));
    return d;
  };

  int q = 0;
  auto query = [&](int x, int y) {
    ++q;
    assert(abs(x) <= B && abs(y) <= B);
    int d = 1e9;

    if(DEB) {
      d = min(d, close(x,_ver));
      d = min(d, close(y,_hor));
    }
    else {
      cout << "0 " << x << " " << y << endl;
      cin >> d;
    }
    return d;
  };

  auto answer = [&](set<int> ver, set<int> hor) {
    cout << "1 " << sz(ver) << " " << sz(hor) << endl;
    for(int x : ver) cout << x << " ";
    cout << endl;
    for(int x : hor) cout << x << " ";
    cout << endl;

    debug(q);

    if(DEB) {
      //debug(ver); debug(hor);
      assert(ver == _ver);
      assert(hor == _hor);
    }

    assert(q <= 3e5);

    exit(0);
  };

  set<pii> maybe;
  set<int> ver, hor;
  addInterval(maybe, -B, B+1);

  auto contained = [&](int x, auto&s) {
    auto it = s.lower_bound(pii(x+1,-1e9));
    if(it == begin(s)) return false;
    return x < prev(it)->second;
  };
  auto rem = [&](int x, int d) { removeInterval(maybe, x-d, x+d+1); };
  auto go = [&](int x, int y) {
    if(!contained(x,maybe)) return -1;
    if(!contained(y,maybe)) return -1;

    int d = query(x,y);
    rem(x,max(d,1)-1);
    rem(x,max(d,1)-1);
    if(d == 0) {
      if(0 == query(x,uid(rng)) && 0 == query(x,uid(rng))) ver.emplace(x);
      if(0 == query(uid(rng),y) && 0 == query(uid(rng),y)) hor.emplace(y);
    }
    return d;
  };

  while(sz(maybe)) {
    int x,y;
    x = y = begin(maybe)->first + (begin(maybe)->second-begin(maybe)->first)/2;

    int d = go(x,y);
    //debug(); debug(x,y,d); debug(maybe_ver); debug(maybe_hor); debug(ver); debug(hor);

    assert(d >= 0);
    int dd = 1e9;
    dd = min(dd, close(x,ver));
    dd = min(dd, close(y,hor));
    //debug(dd);
    assert(dd >= d);
    if(d != dd) {
      go(x+d,y);
      go(x-d,y);
      go(x,y+d);
      go(x,y-d);
    }
  }

  answer(ver, hor);
}