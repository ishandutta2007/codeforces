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

int T, N, M;

bool isIn(int x, vector<int>& a){
  return binary_search(a.begin(), a.end(), x);
}

int solve(vector<int>& a, vector<int>& b){
  int rbox=0, rkey=0;
  int cntB = 0;
  int add = 0;
  for(int x : a){
    add += isIn(x, b);
  }
  int curSol = 0;
  int bst = 0;
  for(int lkey=0; lkey<sz(b); lkey++){
    int x = b[lkey];
    while(rbox < sz(a) && x+cntB >= a[rbox]){
      cntB++;
      rbox++;
    }
    while(rkey < sz(b) && x+cntB-1 >= b[rkey]){
      if(isIn(b[rkey], a))
        add--;
      if(b[rkey] >= x)
        curSol++;
      rkey++;
    }
    bst = max(bst, curSol + add);
    if(cntB > 0)
      curSol--;
  }
  return bst;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> N >> M;
    vector<int> A[2], B[2];
    for(int i=0; i<N; i++){
      int x;
      cin >> x;
      A[x>0].push_back(abs(x));
    }
    for(int i=0; i<M; i++){
      int x;
      cin >> x;
      B[x>0].push_back(abs(x));
    }
    reverse(A[0].begin(), A[0].end());
    reverse(B[0].begin(), B[0].end());
    int res = solve(A[0], B[0]) + solve(A[1], B[1]);
    cout << res << endl;
  }
}