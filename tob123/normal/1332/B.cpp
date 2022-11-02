#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 1e5+10;

int N, T;
int A[n];
bool b[n];
vector<int> C[n];
int col[n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> N;
    for(int i=0; i<N; i++){
      cin >> A[i];
      b[i] = false;
    }
    int cnt = 0;
    for(int i=2; i<100; i++){
      C[i].clear();
      for(int j=0; j<N; j++){
        if(!b[j] && A[j]%i == 0){
          b[j] = true;
          C[i].push_back(j);
        }
      }
      if(sz(C[i]))
        cnt++;
    }
    cout << cnt << "\n";
    int curC = 1;
    for(int i=2; i<100; i++){
      if(sz(C[i])){
        for(int x : C[i])
          col[x] = curC;
        curC++;
      }
    }
    for(int i=0; i<N; i++){
      cout << col[i] << " ";
    }
    cout << "\n";
  }

  return 0;
}