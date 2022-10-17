#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repp(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perr(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"Yes"<<endl;
#define CNO cout<<"No"<<endl;

typedef long long LL;
typedef long double LD;

class UnionFind{
private:
  vector<int> node;

public:
  UnionFind(int n){
    node = vector<int>(n);
    for(int i = 0; i < n; i++){
      node[i] = -1;
    }
  }

  int root(int x){
    if(node[x] < 0) return x;
    else return node[x] = root(node[x]);
  }

  int size(int x){
    return -node[root(x)];
  }

  bool eql(int x, int y){
    if(root(x) == root(y)) return true;
    else return false;
  }

  bool uni(int x, int y){
    x = root(x);
    y = root(y);
    if(x == y) return false;
    if(node[x] > node[y]) swap(x, y);
    node[x] += node[y];
    node[y] = x;
    return true;
  }
};


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n,m;
  cin >> n >> m;
  UnionFind uf(n);
  rep(i,m){
    int k;
    cin >> k;
    if(k==0) continue;
    int x,y;
    cin >> x;
    rep(j,k-1){
      cin >> y;
      uf.uni(x-1,y-1);
    }
  }
  rep(i,n){
    cout << uf.size(i) << " ";
  }
  cout << endl;
  return 0;
}