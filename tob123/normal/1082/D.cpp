#include <bits/stdc++.h>
using namespace std;

const int n = 505;

int N;
int A[n];
vector<int> G[n];
bool used[n];

int main(){
  cin >> N;
  for(int i=1; i<=N; i++){
    cin >> A[i];
  }
  int curN = 1, last=2;
  for(int i=1; i<=N; i++){
    if(A[i] == 1){
      curN = last;
      last = i;
    }
  }
  used[curN] = true;
  used[last] = true;
  int dia = 0;
  for(int i=1; i<=N; i++){
    if(used[i])
      continue;
    if(A[i] > 1){
      G[curN].push_back(i);
      A[curN]--;
      used[i] = true;
      A[i]--;
      curN = i;
      dia++;
    }
  }
  G[curN].push_back(last);
  A[curN]--;
  A[last]--;
  dia++;
  for(int i=1; i<=N; i++){
    if(!used[i]){
      bool found = false;
      for(int j=1; j<=N; j++){
        if(used[j] && A[j] > 0){
          G[j].push_back(i);
          found = true;
          A[j]--;
          A[i]--;
          used[i] = true;
          break;
        }
      }
      if(!found){
        cout << "NO" << endl;
        return 0;
      }
    }
  }

  int kanten = 0;
  for(int i=1; i<=N; i++){
    kanten += G[i].size();
  }

  cout << "YES " << dia << endl;
  cout << kanten << endl;
  for(int i=1; i<=N; i++){
    for(int x : G[i]){
      cout << i << " " << x << "\n";
    }
  }

  return 0;
}