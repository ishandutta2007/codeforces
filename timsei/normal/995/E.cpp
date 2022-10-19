#include <bits/stdc++.h>
using namespace std;

const int N = 11111111;

#define int long long

int u, v, mod;

int Pow(int x, int y) {
  int res = 1;
  for(; y; y >>= 1, x = x * x % mod) {
    if(y & 1) {
      res = res * x % mod;
    }
  }
  return res;
}

namespace {
  int add(int x) {return (x >= mod) ? x - mod : x;}
  int sub(int x) {return (x < 0) ? x + mod : x;}
  void Add(int &x, int y) {x = add(x + y);}
  void Sub(int &x, int y) {x = sub(x - y);}
}

vector <int> ans1, ans2, res1, res2;

struct NODE {
  int x, y;
};

vector <int> solve(int x, int y) {
  vector <int> cxt;
  cxt.clear();
  if(x == 1) return cxt;
  if(x == 0) {
    cxt.push_back(1);
    return cxt;
  }
  NODE now = (NODE){x * y % mod, y};
  while(1) {
    if(now.x == now.y) {
      return cxt;
    }
    if(cxt.size() > 200) return cxt;
    if(now.x < now.y) {
      cxt.push_back(3);
      swap(now.x, now.y);
    }
    else {
      now.x -= now.y;
      cxt.push_back(2);
    }
  }
  return cxt;
}

main(void) {
  cin >> u >> v >> mod;
  while(1) {
    int k = (rand() % 32678 * 32768 + rand()) % (mod - 1) + 1;
    res1 = solve(u, k);
    if(!ans1.size() || res1.size() < ans1.size()) ans1 = res1;
    res2 = solve(v, k);
    if(!ans2.size() || res2.size() < ans2.size()) ans2 = res2;
    if(ans1.size() + ans2.size() <= 200) break;
  }
  if(u == v) {
    cout << 2 << endl;
    cout << 3 <<" " << 3 << endl;
    return 0;
  }
  cout << ans1.size() + ans2.size() << endl;
  for(int i = 0; i < (int) ans1.size(); ++ i) cout << ans1[i] << " ";
  for(int i = (int)ans2.size() - 1; i >= 0; -- i) {
    if(ans2[i] == 2) cout << 1 <<" ";
    else if(ans2[i] == 1) cout << 2 <<" ";
    else cout << 3 <<" ";
  }
  puts("");
}