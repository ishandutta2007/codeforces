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

const int n = 200200;

int pref[n][101];
vector<int> firstI[101][101];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> A(N+1);
  for(int i=1; i<=N; i++){
    cin >> A[i];
    A[i]--;
  }
  for(int i=0; i<100; i++)
    for(int j=0; j<100; j++)
      firstI[i][j].push_back(0);
  int bst = 0;
  for(int i=1; i<=N; i++){
    int bi = 0;
    pref[i][A[i]]++;
    for(int j=0; j<100; j++){
      pref[i][j] += pref[i-1][j];
      if(pref[i][j] >= pref[i][bi])
        bi = j;
    }
    //cout << i << " bi: " << bi << endl;
    for(int j=0; j<100; j++){
      if(j == bi)
        continue;
      int d = pref[i][bi] - pref[i][j];
      //cout << "try: " << j << " -> " << d << endl;
      if(d < sz(firstI[bi][j])){
        //cout << firstI[bi][j][d] << endl;
        bst = max(bst, i-firstI[bi][j][d]);
      }
    }
    for(int j=0; j<100; j++){
      int d = pref[i][A[i]]-pref[i][j];
      /*
      if(i == 1 && j == 1){
        cout << "----- " << d << " " << sz(firstI[0][1]) << endl;
      }
      */
      if(A[i] != j && d >= sz(firstI[A[i]][j])){
        firstI[A[i]][j].push_back(i);
      }
    }
  }
  //print(firstI[0][1]);
  cout << bst << "\n";
}