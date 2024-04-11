#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int q;
  cin >> q;

  set<pii> by_idx, by_money;
  int idx = 1;

  rep(i,0,q) {
    int t;
    cin>>t;
    if(t == 1) {
      int x;
      cin>>x;
      by_idx.emplace(idx,x);
      by_money.emplace(-x,idx);
      ++idx;
    }
    else if(t == 2) {
      auto [i, x] = *begin(by_idx);
      cout << i << " ";
      by_idx.erase(pii{i,x});
      by_money.erase(pii{-x,i});
    }
    else if(t == 3) {
      auto [x,i] = *begin(by_money);
      x = -x;
      cout << i << " ";
      by_idx.erase(pii{i,x});
      by_money.erase(pii{-x,i});
    }
    else assert(false);
  }
  cout << endl;
}