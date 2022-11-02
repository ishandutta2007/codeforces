#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
typedef long long ll;
typedef pair<int,int> pii;
template<class T> void print(T & x){ cout << x; }
template<class T,class U> void print(pair<T,U> & p){cout << "("; print(p.first); cout << ", "; print(p.second); cout << ")"; }
template<class T> void print(vector<T> & v) {
  cout << "{";
  if (sz(v)) print(v[0]);
  for (int i = 1; i < sz(v); i++) cout << ", ", print(v[i]);
  cout << "}\n";
}

const int ssize = 1024*1024*4;
const int offset = ssize/2-1;
const int INF = 1e9;

int S[ssize];
int L[ssize];

int left(int x){ return 2*x+1; }
int right(int x){ return 2*x+2; }

void prop(int cur){
  if(L[cur] != -1){
    S[left(cur)] = S[right(cur)] = L[left(cur)] = L[right(cur)] = L[cur];
    L[cur] = -1;
  }
}

void upd(int l, int r, int x, int curl=0, int curr=offset, int cur=0){
  if(curl > r || curr < l)
    return;
  if(l <= curl && r >= curr){
    S[cur] = x;
    L[cur] = x;
    return;
  }
  prop(cur);
  int m = (curl+curr)/2;
  upd(l, r, x, curl, m, left(cur));
  upd(l, r, x, m+1, curr, right(cur));
  S[cur] = min(S[left(cur)], S[right(cur)]);
}

int query(int l, int r, int curl=0, int curr=offset, int cur=0){
  if(curl > r || curr < l)
    return INF;
  if(l <= curl && r >= curr)
    return S[cur];
  prop(cur);
  int m = (curl+curr)/2;
  return min(
      query(l, r, curl, m, left(cur)),
      query(l, r, m+1, curr, right(cur))
      );
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  L[0] = -INF;
  S[0] = -INF;
  for(int i=1; i<ssize; i++)
    L[i] = -1;
  vector<tuple<int,int,int>> A;
  for(int i=0; i<N; i++){
    int l, r, w;
    cin >> l >> r >> w;
    l--; r--;
    A.emplace_back(w, l, r);
  }
  int bst = 1e7;
  sort(A.begin(), A.end());
  for(auto [w, l, r] : A){
    //cout << "set " << l << " - " << r << ": " << w << endl;
    upd(l, r-1, w);
    //cout << " -> " << query(0, M-2) << endl;
    bst = min(bst, w-query(0, M-2));
  }
  cout << bst << endl;
}