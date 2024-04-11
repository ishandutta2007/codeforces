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

vector<int> A;
int T, N, K;

int query(vector<int>& x){
  cout << "? " << sz(x);
  for(int y : x)
    cout << " " << y;
  cout << endl;
  int z;
  cin >> z;
  if(z == -1){
    exit(1);
  }
  return z;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  vector<int> cur;
  while(T--){
    cin >> N >> K;
    vector<set<int>> S(K);
    A.resize(N);
    for(int i=0; i<N; i++){
      A[i] = i+1;
    }
    for(int i=0; i<K; i++){
      int c;
      cin >> c;
      for(int j=0; j<c; j++){
        int x;
        cin >> x;
        S[i].insert(x);
      }
    }
    int l=0, r=sz(A)-1;
    int mx = query(A);
    while(l < r){
      int mid = (l+r+1)/2;
      cur.clear();
      for(int i=l; i<mid; i++)
        cur.push_back(A[i]);
      if(query(cur) == mx){
        r = mid-1;
      }
      else
        l = mid;
    }
    int s = -1;
    for(int i=0; i<K; i++){
      for(int j : S[i]){
        if(j == A[l]){
          if(s != -1)
            exit(1);
          s = i;
        }
      }
    }
    int res2 = mx;
    if(s != -1){
      cur.clear();
      for(int i=1; i<=N; i++){
        if(!S[s].count(i))
          cur.push_back(i);
      }
      res2 = query(cur);
    }
    cout << "! ";
    for(int i=0; i<K; i++){
      if(i == s)
        cout << res2 << " ";
      else
        cout << mx << " ";
    }
    cout << endl;
    string str;
    cin >> str;
    if(str != "Correct"){
      cerr << "failed" << endl;
      return 1;
    }
  }
}