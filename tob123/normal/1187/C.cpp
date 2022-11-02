#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
const int n = 1500;

int N, M;
vector<pair<int,int>> A, B;
bool inc[n];

int main(){
  cin >> N >> M;
  for(int i=0; i<M; i++){
    int t, l, r;
    cin >> t >> l >> r;
    l--; r--;
    if(t)
      A.push_back({l, r});
    else
      B.push_back({l, r});
  }
  for(auto p : A){
    for(int i=p.first; i<p.second; i++){
      inc[i] = true;
    }
  }
  for(auto p : B){
    bool pos = false;
    for(int i=p.first; i<p.second; i++){
      pos |= !inc[i];
    }
    if(!pos){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  int last = 5000;
  cout << last;
  for(int i=0; i<N-1; i++){
    if(inc[i]){
      last = last+1;
    }
    else
      last = 5000-i-1;
    cout << " " << last;
  }
  cout << endl;

  return 0;
}