#include <bits/stdc++.h>
using namespace std;

const int n = 2e5+10;

int N;
long double S;
vector<int> G[n];

int main(){
  cin >> N >> S;
  for(int i=0; i<N-1; i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  int cnt = 0;
  for(int i=0; i<N; i++){
    if(G[i].size() == 1){
      cnt++;
    }
  }
  cout << setprecision(20) << fixed << (S/cnt)*2 << endl;

  return 0;
}