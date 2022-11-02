#include <bits/stdc++.h>
using namespace std;

int N, M;
int L[2001][2001];
int cnt[2001];

int main(){
  cin >> N >> M;
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      char c;
      cin >> c;
      if(c == '1')
        L[i][j] = 1;
      cnt[j] += L[i][j];
    }
  }

  for(int i=0; i<N; i++){
    bool flag = true;
    for(int j=0; j<M; j++){
      if(L[i][j] == 1 && cnt[j] == 1){
        flag = false;
        break;
      }
    }
    if(flag){
      cout << "YES" << endl;
      return 0;
    }
  }

  cout << "NO" << endl;

  return 0;
}