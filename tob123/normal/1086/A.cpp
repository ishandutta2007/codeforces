#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

vector<pii> A(3);

int main(){
  for(int i=0; i<3; i++){
    cin >> A[i].first >> A[i].second;
  }
  sort(A.begin(), A.end());

  vector<pii> R;
  for(int i=A[0].first; i < A[1].first; i++){
    R.push_back({i, A[0].second});
  }
  for(int i=A[1].first+1; i <= A[2].first; i++){
    R.push_back({i, A[2].second});
  }
  int miny = min(A[0].second, min(A[1].second, A[2].second));
  int maxy = max(A[0].second, max(A[1].second, A[2].second));
  for(int i=miny; i<=maxy; i++){
    R.push_back({A[1].first, i});
  }

  cout << R.size() << endl;
  for(auto p : R){
    cout << p.first << " " << p.second << endl;
  }

  return 0;
}