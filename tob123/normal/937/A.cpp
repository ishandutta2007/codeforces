#include <bits/stdc++.h>
using namespace std;


int N;
set<int> S;

int main(){
  cin >> N;
  int x;
  for(int i=0; i<N; i++){
    cin >> x;
    S.insert(x);
  }

  int res = S.size();
  if(S.count(0))
    res--;

  cout << res << endl;

  return 0;
}