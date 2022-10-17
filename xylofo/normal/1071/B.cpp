#include <bits/stdc++.h>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)
#define all(c) (c).begin(), (c).end()
#define debug(x) cerr << #x << " = " << x << endl
#define eb emplace_back
#define X first
#define Y second
typedef long long int ll; 
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n,k;
  cin>>n>>k;
  vector<string> v(n);
  rep(i,0,n) cin>>v[i];
  vector<vi> a(n, vi(n,0));
  auto A = [&](int x, int y) {
    return (x >= 0 && y >= 0) ? a[x][y] : 0;
  };
  int mxLeadingAs = 0;
  rep(i,0,n) rep(j,0,n) {
    a[i][j] = max(A(i-1,j), A(i,j-1)) + (v[i][j] == 'a' ? 1 : 0);
    if(a[i][j] + k >= i+j+1) mxLeadingAs = max(mxLeadingAs, i+j+1);
  }
  //debug(mxLeadingAs);

  vector<pair<int,int> > pos;
  rep(i,0,n) rep(j,0,n) {
    if(a[i][j]+k >= i+j+1 && mxLeadingAs == i+j+1)
      pos.eb(i,j);
  }
  if(mxLeadingAs == 0) pos.eb(-1,0);
  rep(i,0,mxLeadingAs) cout << 'a';

  rep(diag, mxLeadingAs, 2*n-1) {
    set<pair<int,int> > npos;
    char c = 'z';
    auto ins = [&](int x, int y) {
      if(x >= 0 && y >= 0 && x < n && y < n) {
        npos.emplace(x,y);
        c = min(c, v[x][y]);
      }
    };
    for(auto p:pos) {
      ins(p.X, p.Y+1);
      ins(p.X+1, p.Y);
    }
    pos.clear();
    for(auto p:npos) if(v[p.X][p.Y] == c) pos.eb(p);
    cout << c;
  }
  cout << endl;
  return 0;
}