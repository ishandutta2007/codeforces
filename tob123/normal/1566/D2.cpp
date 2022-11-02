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
  int T;
  cin >> T;
  while(T--){
    int N, M;
    cin >> N >> M;
    vector<pii> A(N*M);
    vector<int> S(N*M);
    for(int i=0; i<N*M; i++){
      cin >> A[i].first;
      A[i].second = -i;
    }
    sort(A.begin(), A.end());
    int ind = 0;
    while(ind < N*M){
      int to = ind+1;
      while(to < N*M && A[to].first == A[ind].first)
        to++;
      to--;
      if(ind/M == to/M){
        for(int i=ind; i<=to; i++){
          S[i] = A[i].second;
        }
      }
      else{
        int to2 = (ind/M)*M+M-1;
        int from2 = to/M*M;
        int cnt1 = to2-ind+1;
        int cnt2 = to-from2+1;
        for(int i=0; i<cnt1; i++){
          S[ind+i] = A[to-cnt1+1+i].second;
        }
        for(int i=0; i<cnt2; i++){
          S[from2+i] = A[ind+i].second;
        }
        for(int j=0; j<to-ind+1-cnt1-cnt2; j++){
          S[ind+cnt1+j] = A[ind+cnt2+j].second;
        }
      }
      ind = to+1;
    }
    /*
    for(int i=0; i<N*M; i++){
      cout << S[i] << " ";
      if(i%M == M-1)
        cout << endl;
    }
    */
    int sum = 0;
    for(int i=0; i<N*M; i++){
      for(int j=i/M*M; j<i; j++){
        sum += S[j] > S[i];
      }
    }
    cout << sum << "\n";
  }
}