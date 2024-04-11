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

const ll MOD = 998244353;
int T, N, K;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> N >> K;
    vector<int> A(N), B(K), invA(N);
    for(int i=0; i<N; i++){
      cin >> A[i];
      A[i]--;
      invA[A[i]] = i;
      //A2.insert(i);
    }
    set<int> b2;
    for(int i=0; i<K; i++){
      cin >> B[i];
      B[i]--;
      b2.insert(B[i]);
    }
    ll res = 1;
    for(int i=0; i<K; i++){
      b2.erase(B[i]);
      bool lpos = true, rpos = true;
      if(invA[B[i]] == 0 || b2.count(A[invA[B[i]]-1])){
        lpos = false;
      }
      if(invA[B[i]] >= N-1 || b2.count(A[invA[B[i]]+1])){
        rpos = false;
      }
      if(rpos && lpos){
        //cout << "*2" << endl;
        (res *= 2) %= MOD;
      }
      else if(!rpos && !lpos){
        res = 0;
      }
      else{
        //cout << "*1" << endl;
      }
    }
    cout << res << "\n";
  }
}