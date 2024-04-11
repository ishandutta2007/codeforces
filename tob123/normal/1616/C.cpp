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
    for(int i=0; i<N; i++){
      cin >> A[i];
    }
    int bst = max(0, N-2);
    for(int f=0; f<N; f++){
      for(int s=0; s<N; s++){
        if(s == f) continue;
        int cd = __gcd(A[f]-A[s], f-s);
        int jmp = (f-s)/cd;
        int dif = (A[f]-A[s])/cd;
        if(jmp < 0){
          jmp *= -1;
          dif *= -1;
        }
        dif *= -1;
        int cnt = 0;
        for(int j=0; j*jmp<=f; j++){
          if(A[f-j*jmp] == A[f]+j*dif) cnt++;
        }
        for(int j=1; j*jmp<N-f; j++){
          if(A[f+j*jmp] == A[f]-j*dif) cnt++;
        }
        bst = min(bst, N-cnt);
      }
    }
    cout << bst << endl;
  }
}