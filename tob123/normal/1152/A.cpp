#include <bits/stdc++.h>
using namespace std;

const int n = 1e5+10;

int N, M;
int c1[n];
int c2[n];

int main(){
  cin >> N >> M;

  int x;
  for(int i=0; i<N; i++){
    cin >> x;
    c1[x%2]++;
  }
  for(int i=0; i<M; i++){
    cin >> x;
    c2[x%2]++;
  }

  int res = 0;
  res += min(c1[0], c2[1]);
  res += min(c1[1], c2[0]);
  
  cout << res << endl;

  return 0;
}