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

vector<pii> Q;

int fi = 0;

deque<int> comb(deque<int> a, deque<int> b){
  deque<int> r;
  for(int i=0; i<sz(a); i++){
    Q.emplace_back(a[i], b[i]);
    r.push_back(a[i]);
    r.push_back(b[i]);
  }
  return r;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  for(int i=1; i<=N; i*=2){
    for(int j=0; j+2*i<=N; j+=2*i){
      for(int k=0; k<i; k++){
        if(i+j+k < N){
          Q.emplace_back(j+k+1, j+i+k+1);
        }
      }
    }
  }
  deque<deque<int>> S;
  int ind = N;
  for(int b=1; b<=N; b<<=1){
    if(b & N){
      S.resize(sz(S)+1);
      for(int i=0; i<b; i++){
        S.back().push_back(ind--);
      }
    }
  }
  //print(Q);
  while(sz(S) > 2){
    auto q1 = S[0];
    auto q2 = S[1];
    if(sz(q1) == sz(q2)){
      S.pop_front();
      S.pop_front();
      S.push_front(comb(q1, q2));
    }
    else{
      deque<int> z;
      for(int i=0; i<sz(q1); i++){
        z.push_back(S.back().back());
        S.back().pop_back();
      }
      S.pop_front();
      S.push_front(comb(q1, z));
    }
  }
  cout << sz(Q) << endl;
  for(auto [a, b] : Q){
    cout << a << " " << b << "\n";
  }
}