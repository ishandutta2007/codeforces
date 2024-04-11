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

void bad(){
  cout << "No" << endl;
  exit(0);
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(NULL);
  int n,m;
  cin>>n>>m;
  vector<vi> a(n, vi(m,0));
  rep(_,0,2) rep(i,0,n) rep(j,0,m) {
    int x;
    cin>>x;
    a[i][j] ^= x;
  }
  rep(i,0,n) {
    int cnt = 0;
    rep(j,0,m) cnt += a[i][j];
    if(cnt % 2) bad();
  }
  rep(j,0,m) {
    int cnt = 0;
    rep(i,0,n) cnt += a[i][j];
    if(cnt % 2) bad();
  }
  cout << "Yes" << endl;
  return 0;
}