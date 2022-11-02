#include <bits/stdc++.h>
using namespace std;

const int n = 1e5+10;

int N, T;
vector<pair<pair<int,int>, int>> A;
int group[n];

int main(){
  cin >> T;
  while(T--){
    cin >> N;
    A.resize(N);
    for(int i=0; i<N; i++){
      cin >> A[i].first.first >> A[i].first.second;
      A[i].second = i;
      group[i] = 2;
    }
    sort(A.begin(), A.end());
    bool found = false;
    int maxR = -1;
    for(int i=0; i<N-1; i++){
      maxR = max(maxR, A[i].first.second);
      group[A[i].second] = 1;
      if(maxR < A[i+1].first.first){
        found = true;
        break;
      }
    }
    if(found){
      for(int i=0; i<N; i++){
        cout << group[i] << " ";
      }
      cout << "\n";
    }
    else{
      cout << -1 << "\n";
    }
  }

  return 0;
}