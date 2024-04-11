#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> ti;

int M, N, K, T;
vector<int> A;
vector<ti> B;

bool pos(int x){
  int rr=0;
  int res = 0;
  for(auto t : B){
    int l, r, a;
    tie(l, r, a) = t;
    if(a > x){
      res += max(min(r-l+1, r-rr), 0);
      rr = max(r, rr);
    }
  }
  return res*2+N+1 <= T;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> M >> N >> K >> T;
  A.resize(M);
  for(int i=0; i<M; i++){
    cin >> A[i];
  }
  sort(A.rbegin(), A.rend());
  for(int i=0; i<K; i++){
    int l, r, d;
    cin >> l >> r >> d;
    B.push_back(make_tuple(l, r, d));
  }
  sort(B.begin(), B.end());
  int l = 0, r = M;
  while(l < r){
    int m = (l+r+1)/2;
    if(pos(A[m-1])){
      l = m;
    }
    else{
      r = m-1;
    }
  }
  cout << l << endl;

  return 0;
}