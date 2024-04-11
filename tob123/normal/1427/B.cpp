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


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T, N, K;
  string S;
  cin >> T;
  while(T--){
    cin >> N >> K >> S;
    deque<int> A;
    A.push_back(0);
    int lst = -2, lst2 = -1;
    int sc = 0;
    int cnt = 0;
    S.push_back('L');
    for(int i=0; i<N+1; i++){
      if(S[i] == 'W'){
        cnt++;
        if(lst == i-1){
          sc += 2;
        }
        else{
          sc++;
        }
        lst = i;
      }
      else{
        if(lst2 == i-1){
          A.back()++;
        }
        else{
          A.push_back(1);
        }
        lst2 = i;
      }
    }
    /*
    cout << S << endl;
    cout << "A: ";
    for(auto x : A)
      cout << x << " ";
    cout << endl;
    */
    if(K == 0){
      cout << sc << "\n";
      continue;
    }
    if(sc == 0){
      cout << 2*K-1 << "\n";
      continue;
    }
    else{
      if(K >= N - cnt){
        cout << 2*N-1 << "\n";
        continue;
      }
      A.pop_front();
      A.pop_back();
      sort(A.begin(), A.end());
      while(sz(A) && A[0] <= K){
        K -= A[0];
        sc += 2*A[0]+1;
        A.pop_front();
      }
      sc += 2*K;
      cout << sc << "\n";
    }
  }
}