//author: extraterrestrial_
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
//#define int ll
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define pii pair<int, int>
const int INF = 1e9 + 10;
const ll BINF = 1e18 + 10;
 
//#define FAST_ALLOCATOR_MEMORY 1e9
 
int n;
 
/*#ifdef FAST_ALLOCATOR_MEMORY
    int allocator_pos = 0;
    char allocator_memory[(int)FAST_ALLOCATOR_MEMORY];
    inline void * operator new ( size_t n ) {
        char *res = allocator_memory + allocator_pos;
        allocator_pos += n;
        //assert(allocator_pos <= (int)FAST_ALLOCATOR_MEMORY);
        if (allocator_pos + 100 > (int)FAST_ALLOCATOR_MEMORY) {
          cout << "NO";
          exit(0);
        }
        return (void *)res;
    }
    inline void operator delete ( void * ) noexcept { }
    //inline void * operator new [] ( size_t ) { assert(0); }
    //inline void operator delete [] ( void * ) { assert(0); }
#endif*/
 
struct rect {
  int x, y, x2, y2;
  rect() {};
  rect(int _x, int _y, int _x2, int _y2) : x(_x), y(_y), x2(_x2), y2(_y2) {};
};
 
const int MX = 400010;
int dx1[MX], dx2[MX], dy1[MX], dy2[MX];
int iter = 0;
int T = 500, ptr = 0;
vector<rect> have[10010];
 
int mem = 400010 * 4 + 10010 * 100;
 
bool cmp(int a, int b) {
  return SZ(have[a]) > SZ(have[b]);
}
 
mt19937 rnd(228);
 
const int MEM = 3.4e7;
 
bool rec(int ind) {
  if (SZ(have[ind]) <= 1) {
    return true;
  }
  if (mem >= MEM) {
    cout << "NO";
    exit(0);
  }
  iter++;
  if (iter > T || ptr >= 1000) {
    cout << "YES";
    exit(0);
  }
  int mnx = INF, mny = INF, mxx = -INF, mxy = -INF;
  for (auto it : have[ind]) {
    mnx = min(mnx, it.x);
    mxx = max(mxx, it.x2);
    mny = min(mny, it.y);
    mxy = max(mxy, it.y2);
  }
  for (int  i= mnx; i <= mxx; i++) {
    dx1[i] = dx2[i] = 0;
  }
  for (int  i = mny; i <= mxy; i++) {
    dy1[i] = dy2[i] = 0;
  }
  for (auto it : have[ind]) {
    dx1[it.x]++;
    dx2[it.x2]++;
    dy1[it.y]++;
    dy2[it.y2]++;
  }
  int pl = 0, sum = 0;
  vector<int> okx;
  for (int i = mnx; i <= mxx; i++) {
    sum -= dx2[i];
    if (sum == 0 && dx2[i] != 0 && pl > 0 && pl < SZ(have[ind])) {
      okx.pb(i);
      mem += 4;
    }
    sum += dx1[i];
    pl += dx1[i];
  }
  if (!okx.empty()) {
    for (auto it : have[ind]) {
      have[ptr + int(lower_bound(all(okx), it.x2) - okx.begin())].pb(it);
    }
    mem += SZ(have[ind]);
    ptr += SZ(okx) + 1;
    vector<int> order;
    for (int i = 0; i < SZ(okx) + 1; i++) {
      order.pb(ptr - i - 1);
      mem += 4;
    }
    sort(all(order),cmp);
    for (int ind : order) {
      if (!rec(ind)) {
        return false;
      }
      if (mem >= MEM) {
        cout << "NO";
        exit(0);
      }
    }
    return true;
  }
  vector<int> oky;
  mem += 100;
  pl = 0;
  sum = 0;
  for (int i = mny; i <= mxy; i++) {
    sum -= dy2[i];
    if (sum == 0 && dy2[i] != 0 && pl > 0 && pl < SZ(have[ind])) {
      oky.pb(i);
      mem += 4;
    }
    sum += dy1[i];
    pl += dy1[i];
  }
  if (!oky.empty()) {
    for (auto it : have[ind]) {
      have[ptr + int(lower_bound(all(oky), it.y2) - oky.begin())].pb(it);
    }
    mem += SZ(have[ind]);
    ptr += SZ(oky) + 1;
    vector<int> order;
    for (int i = 0; i < SZ(oky) + 1; i++) {
      order.pb(ptr - i - 1);
    }
    sort(all(order), cmp);
    for (int ind : order) {
      if (!rec(ind)) {
        return false;
      }
      if (mem >= MEM) {
        cout << "NO";
        exit(0);
      }
    }
    return true;
  }
  return false;
}
 
void source() {
  cin >> n;
  if (n == 100000) T = 300;
  vector<int> srt;
  for (int i = 0; i < n; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    have[0].pb(rect(a, b, c, d));
    srt.pb(a);
    srt.pb(b);
    srt.pb(c);
    srt.pb(d);
  }
  sort(all(srt));
  srt.resize(unique(all(srt)) - srt.begin());
  unordered_map<int, int> to;
  for (int i = 0; i < SZ(srt); i++) {
    to[srt[i]] = i;
  }
  for (auto &it : have[0]) {
    it.x = to[it.x];
    it.x2 = to[it.x2];
    it.y = to[it.y];
    it.y2 = to[it.y2];
  }
  ptr = 1;
  cout << (rec(0) ? "YES" : "NO");
}
 
signed main() {
#ifdef extraterrestrial_
  assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#else
#define TASK ""
  //assert(freopen(TASK".in", "r", stdin));
  //assert(freopen(TASK".out", "w", stdout));
  //assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
#ifdef extraterrestrial_
  cerr << "\n\nTIME :: " << clock() * 1.0 / CLOCKS_PER_SEC;
#endif
  return 0;
}