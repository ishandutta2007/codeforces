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

vector<vector<int>> Q;
int n,k;

bool rec(int i, const vector<int>& cur) {
  if(i==k) {
    rep(i,0,n-1) {
      if(cur[i] == -1) return false;
      if(cur[i] > cur[i+1]) return false;
    }
    return true;
  }
  int qu = 0;
  int ze = 0;
  int on = 0;
  rep(j,0,Q[i].size()) {
    if(cur[Q[i][j]]==-1) ++qu;
    if(cur[Q[i][j]]==0) ++ze;
    if(cur[Q[i][j]]==1) ++on;
  }
  rep(z,0,qu+1) {
    vector<int> cur2 = cur;
    rep(j,0,ze+z) {
      cur2[Q[i][j]]=0;
    }
    rep(j,ze+z,Q[i].size()) {
      cur2[Q[i][j]]=1;
    }
    if(!rec(i+1,cur2)) return false;
  }
  return true;
}

int main() {
  cin >> n >> k;
  Q.resize(k);
  rep(i,0,k) {
    int q; cin >> q;
    Q[i].resize(q);
    rep(j,0,q) {
      cin >> Q[i][j];
      --Q[i][j];
    }
  }
  vector<int> start(n,-1);
  if(!rec(0,start)) {
    cout << "REJECTED" << endl;
    return 0;
  }
  cout << "ACCEPTED" << endl;
}