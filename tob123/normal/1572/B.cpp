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
  int T, N;
  cin >> T;
  while(T--){
    cin >> N;
    vector<int> A(N);
    int sum = 0;
    int sum2 = 0;
    for(int i=0 ; i<N; i++ ){
      cin >> A[i];
      sum ^= A[i];
      sum2 += A[i];
    }
    int cnt1 = 0;
    for(int i=0; i<N; i++){
      if(A[i] != 1)
        break;
      cnt1++;
    }
    int cnt2 = 0;
    for(int i=N-1;i>=0; i--){
      if(A[i] != 1)
        break;
      cnt2++;
    }
    if(sum != 0 || sum2 == N || cnt1 == N){
      cout << "NO\n";
      continue;
    }
    vector<int> res;
    if(cnt1%2 != 0){
      cnt1 = 0;
      for(int i=0; i<N-1; i++){
        if(A[i] == 0){
          if(cnt1%2 == 0)
            break;
          if(A[i+1] == 0){
            A[i] = A[i+1] = 1;
            res.push_back(i-1);
            cnt1++;
          }
          else{
            res.push_back(i-1);
            A[i+1] = A[i-1] = 0;
            cnt1--;
            break;
          }
        }
        else
          cnt1++;
      }
    }
    //cout << "cnt1: " << cnt1 << endl;
    cnt1 = 0;
    for(int i=0; i<N; i++){
      if(A[i] != 1)
        break;
      cnt1++;
    }
    //cout << cnt1 << endl;
    if(cnt1 == N){
      cout << "NO\n";
      continue;
    }
    for(int i=cnt1; i>=2; i-=2){
      res.push_back(i-2);
      A[i-1] = A[i-2] = 0;
    }
    for(int i=0; i<N-1; i++){
      if(A[i] == 1){
        if(A[i+1] == 1){
          res.push_back(i-1);
          A[i] = A[i+1] = 0;
        }
        else{
          if(A[i+2] == 1){
            res.push_back(i);
            A[i] = A[i+2] = 0;
          }
          else{
            res.push_back(i);
            res.push_back(i-1);
            A[i+2] = 1;
            A[i] = 0;
          }
        }
      }
    }
    cout << "YES\n";
    cout << sz(res) << "\n";
    for(int x : res){
      cout << x+1 << " ";
    }
    cout << "\n";

  }
}