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

int T, N;
int cnt[2100];

int getMex(vector<int> & A){
  for(int i=0; i<2*N; i++)
    cnt[i] = 0;
  for(int x : A)
    cnt[x]++;
  for(int i=0; i<=2*N;i++)
    if(cnt[i] == 0)
      return i;
  return -100;
}

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
    vector<int> R;
    while(!is_sorted(A.begin(), A.end())){
      //print(A);
      int mex = getMex(A);
      //cout << mex << endl;
      if(mex >= N){
        for(int i=0; i<N; i++){
          if(A[i] != i){
            A[i] = mex;
            R.push_back(i);
            break;
          }
        }
      }
      else{
        //cout << mex << endl;
        A[mex] = mex;
        R.push_back(mex);
      }
    }
    cout << sz(R) << "\n";
    for(int x : R)
      cout << x+1 << " ";
    cout << "\n";
  }
}