#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> A;

int main(){
  cin >> N;
  A.resize(N);
  for(int i=0; i<N; i++){
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  deque<int> d;
  int best = 0;
  for(int x : A){
    d.push_back(x);
    while(d[0] < x-5)
      d.pop_front();
    best = max(best, (int)d.size());
  }

  cout << best << endl;

  return 0;
}