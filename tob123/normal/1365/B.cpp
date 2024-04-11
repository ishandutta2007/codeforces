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

int N, T;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++){
      cin >> A[i];
    }
    int cnt[2] = {0,0};
    for(int j=0; j<N; j++){
      int x;
      cin >> x;
      cnt[x]++;
    }
    if((cnt[0] && cnt[1]) || is_sorted(A.begin(), A.end())){
      cout << "Yes\n";
    }
    else{
      cout << "No\n";
    }
  }
}