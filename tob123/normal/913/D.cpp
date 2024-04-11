#include <bits/stdc++.h>
using namespace std;

int N, T;
vector<pair<pair<int,int>,int>> p;

bool pos(int k){
  int sum=0, t=0;
  for(auto x : p){
    if(x.first.second >= k && x.first.first+t <= T){
      sum++;
      t += x.first.first;
    }
  }
  return sum >= k;
}

void printSol(int k){
  cout << k << endl;
  cout << k << endl;
  int cnt = 0;
  for(auto x : p){
    if(x.first.second >= k && cnt < k){
      cout << x.second << " ";
      cnt++;
    }
  }
  cout << endl;
}

int main(){
  cin >> N >> T;
  p.resize(N);
  for(int i=0; i<N; i++){
    cin >> p[i].first.second >> p[i].first.first;
    p[i].second = i+1;
  }
  sort(p.begin(), p.end());

  /*
  for(int i=0; i<=N; i++){
    cout << i << ": " << pos(i) << endl;
  }
  */

  int l=0, h=N;
  while(l < h){
    int m = (l+h+1)/2;
    if(pos(m)){
      l = m;
    }
    else{
      h = m-1;
    }
  }
  printSol(l);

  return 0;
}