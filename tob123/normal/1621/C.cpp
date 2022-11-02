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

int query(int x){
  int res;
  cout << "? " << x+1 << endl;
  cin >> res;
  res--;
  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T, N;
  cin >> T;
  while(T--){
    cin >> N;
    vector<int> res(N, -1);
    for(int st=0; st<N; st++){
      if(res[st] != -1) continue;
      vector<int> cur;
      cur.push_back(query(st));
      do{
        cur.push_back(query(st));
      }while(cur.back() != cur[0]);
      for(int i=0; i<sz(cur)-1; i++){
        res[cur[i]] = cur[i+1];
      }
    }
    cout << "!";
    for(int x : res){
      cout << " " << x+1;
    }
    cout << endl;
  }
}