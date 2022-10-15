#include <bits/stdc++.h>
#include <array>
#include <unordered_map>
using namespace std;
template<typename T = int> vector<T> create(size_t n){ return vector<T>(n); }
template<typename T, typename... Args> auto create(size_t n, Args... args){ return vector<decltype(create<T>(args...))>(n, create<T>(args...)); }
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
using ll = long long;
using ull = unsigned long long;
using vpi = vector<pair<int, int>>;
using pii = pair<int, int>;
template<typename T>
struct segtree {
    vector<T> t;
    int n;
    segtree(int n): n(n) {
        t.assign(2 * n, T());
    }
    void update(int p, T v){
        for(t[p += n] = v; p >>= 1; )
            t[p] = t[p<<1] + t[p<<1|1];
    }
    void add(int p, T v){
        p += n;
        t[p] = t[p] + v;
        while(p >>= 1) t[p] = t[p<<1] + t[p<<1|1];
    }
    T query(int l, int r){
        T cl = T(), cr = T();
        for(l += n, r += n; l < r; l >>= 1, r >>= 1){
            if(l&1) cl = cl + t[l++];
            if(r&1) cr = t[--r] + cr;
        }
        return cl + cr;
    }
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> p(n);
    for(int i = 0; i < n; i++)
      cin >> p[i];
    const int inf = 1<<30;
    struct mint {
      int v, i, pi;
      mint(){
        v = inf;
        i = -1;
        pi = -1;
      }
      mint(int _i, int _pi): i(_i), pi(_pi) {
        v = i - pi;
      }
      mint operator + (mint oth){
        if(v < oth.v) return *this;
        return oth;
      }
    };
    struct maxt {
      int v, i, pi;
      maxt(){
        v = -inf;
        i = -1;
        pi = -1;
      }
      maxt(int _i, int _pi): i(_i), pi(_pi) {
        v = i + pi;
      }
      maxt operator + (maxt oth){
        if(v > oth.v) return *this;
        return oth;
      }
    };
    segtree<mint> seg_min(n);
    segtree<maxt> seg_max(n);
    for(int i = 0; i < n; i++){
      seg_min.add(i, mint(i, p[i]));
      seg_max.add(i, maxt(i, p[i]));
    }
    queue<int> q;
    a--;
    b--;
    vector<int> dist(n, -1);
    q.push(a);
    seg_max.update(a, maxt());
    seg_min.update(a, mint());
    dist[a] = 0;
    while(!q.empty()){
      int u = q.front(); q.pop();
      vector<int> got;
      if(u){
        int l = max(u - p[u], 0), r = u;
        while(seg_max.query(l, r).v >= u){
          auto it = seg_max.query(l, r);
          got.push_back(it.i);
          seg_max.update(it.i, maxt());
          seg_min.update(it.i, mint());
        }
      }
      if(u + 1 < n){
        int l = u + 1, r = min(u + p[u] + 1, n);
        while(seg_min.query(l, r).v <= u){
          auto it = seg_min.query(l, r);
          got.push_back(it.i);
          seg_max.update(it.i, maxt());
          seg_min.update(it.i, mint());
        }
      }
      sort(got.begin(), got.end());
      got.erase(unique(got.begin(), got.end()), got.end());
      for(int v : got){
        assert(dist[v] == -1);
        if(dist[v] == -1){
          dist[v] = dist[u] + 1;
          q.push(v);
        }
      }
    }
    cout << dist[b] << '\n';
  }
  return 0;
}