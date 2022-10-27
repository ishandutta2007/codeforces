/**
 *    author:  wxhtzdy
 *    created: 15.10.2022 17:13:25
**/
#include <bits/stdc++.h>

using namespace std;

template <typename T>
class fenwick {
  public:
  vector<T> fenw;
  int n;
  fenwick(int _n) : n(_n) {
    fenw.resize(n);
  }
  void modify(int x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }
  T get(int x) {
    T v{};
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};

inline void read(int &x)
{
  char c;int f=1;
  while(!isdigit(c=getchar()))if(c=='-')f=-1;
  x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
  x*=f;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);      
  int n, q;
  read(n);
  read(q);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    read(a[i]);
  }
  vector<int> xs;
  for (int i = 0; i < n; i++) {
    xs.push_back(a[i]);
  }
  vector<int> op(q);
  vector<int> id(q);
  vector<int> x(q);
  vector<int> l(q);
  vector<int> r(q);
  vector<int> k(q);
  for (int i = 0; i < q; i++) {
    read(op[i]);
    if (op[i] == 1) {
      read(id[i]);
      read(x[i]);
      --id[i];
      xs.push_back(x[i]);
    } else {
      read(l[i]);
      read(r[i]);
      read(k[i]);
      --l[i]; --r[i];
    }
  } 
  const int F = 25;
  sort(xs.begin(), xs.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());
  for (int i = 0; i < n; i++) {
    a[i] = lower_bound(xs.begin(), xs.end(), a[i]) - xs.begin();
  }
  for (int i = 0; i < q; i++) {
    if (op[i] == 1) x[i] = lower_bound(xs.begin(), xs.end(), x[i]) - xs.begin(); 
  }
  int sz = (int) xs.size();
  vector<vector<int>> vval(F, vector<int>(sz));
  mt19937 rng(time(0));
  const int MAX = 1e9;
  for (int it = 0; it < F; it++) {
    vector<int> vals;
    while (vals.size() < sz) {
      int x = rng() % MAX;
      vals.push_back(x);       
    }     
    shuffle(vals.begin(), vals.end(), rng);
    for (int j = 0; j < sz; j++) {
      vval[it][j] = vals[j]; 
    }
  }        
  vector<fenwick<long long>> fenw(F, fenwick<long long>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < F; j++) {
      fenw[j].modify(i, vval[j][a[i]]);      
    }
  }
  for (int i = 0; i < q; i++) {
    if (op[i] == 1) {
      for (int j = 0; j < F; j++) {
        fenw[j].modify(id[i], -vval[j][a[id[i]]] + vval[j][x[i]]);      
      }        
      a[id[i]] = x[i];
    } else {
      if (k[i] == 1) {
        cout << "YES" << '\n';
        continue;
      }
      bool ok = true;
      for (int j = 0; j < F; j++) {
        long long s = fenw[j].get(r[i]) - fenw[j].get(l[i] - 1);
        if (s % k[i] > 0) {
           ok = false;
        }
      }
      cout << (ok ? "YES" : "NO") << '\n';
    }
  }                                                  
  return 0;
}