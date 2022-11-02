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

const int n = 2e5+10;

int N;
int A[n], B[n];
int cnt[n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for(int i=0; i<N; i++){
    int x;
    cin >> x;
    x--;
    A[x] = i;
  }
  for(int i=0; i<N; i++){
    int x;
    cin >> x;
    x--;
    B[x] = i;
  }
  for(int i=0; i<N; i++){
    cnt[(B[i]-A[i]+N)%N]++;
  }
  int mx = 0;
  for(int i=0; i<N; i++){
    mx = max(mx, cnt[i]);
  }
  cout << mx << endl;
}