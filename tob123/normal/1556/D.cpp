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

ll qa(int i, int j){
  i++; j++;
  cout << "and " << i << " " << j << endl;
  ll res;
  cin >> res;
  return res;
}
ll qo(int i, int j){
  i++; j++;
  cout << "or " << i << " " << j << endl;
  ll res;
  cin >> res;
  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, K;
  cin >> N >> K;
  vector<ll> A(N);
  ll a01 = qa(0, 1);
  ll a02 = qa(0, 2);
  ll a12 = qa(1, 2);
  ll o01 = qo(0, 1);
  ll o02 = qo(0, 2);
  ll o12 = qo(1, 2);
  for(int b=0; b<32; b++){
    ll ba01 = (a01>>b)&1;
    ll ba02 = (a02>>b)&1;
    ll ba12 = (a12>>b)&1;
    ll bo01 = (o01>>b)&1;
    ll bo02 = (o02>>b)&1;
    ll bo12 = (o12>>b)&1;
    vector<ll> res(3);
    if(ba01 || ba02 || ba12){
      if(ba01){
        res[0] = res[1] = 1;
        res[2] = ba12;
      }
      else if(ba02){
        res[0] = res[2] = 1;
        res[1] = ba12;
      }
      else if(ba12){
        res[2] = res[1] = 1;
        res[0] = ba02;
      }
      //cout << "a" << endl;
    }
    else{
      res[0] = bo01 && bo02;
      res[1] = bo01 && bo12;
      res[2] = bo12 && bo02;
      //cout << "b" << endl;
    }
    //cout << 0 << ": " << res[0] << " " << res[1] << " " << res[2] << endl;
    for(int i=0; i<3; i++)
      A[i] |= res[i]<<b;
  }
  for(int i=3; i<N; i++){
    ll a = qa(0, i);
    ll o = qo(0, i);
    A[i] = a | (o&(~A[0]));
  }
  //print(A);
  sort(A.begin(), A.end());
  cout << "finish " << A[K-1] << endl;
}