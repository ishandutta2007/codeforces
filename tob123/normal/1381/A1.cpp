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
string a, b;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> N >> a >> b;
    int off = 0, mult=1;
    vector<int> A;
    bool f = false;
    for(int i=N-1; i>=0; i--){
      int curI = off + mult*i;
      if((a[curI] != b[i]) ^ f){
        if((a[off] != b[i]) ^ f){
          A.push_back(i+1);
        }
        else{
          A.push_back(1);
          A.push_back(i+1);
        }
        off = off + mult * i;
        mult *= -1;
        f ^= true;
      }
    }
    cout << sz(A);
    for(auto x : A)
      cout << " " << x;
    cout << "\n";
  }
}