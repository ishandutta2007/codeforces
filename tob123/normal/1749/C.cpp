#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int) ((x).size()))
typedef long long ll;
typedef pair<int,int> pii;

int main(){
  int T;
  cin >> T;
  while(T--){
    int N;
    cin >> N;
    vector<int> A(N+1);
    for(int i=0; i<N; i++){
      int x;
      cin >> x;
      A[x]++;
    }
    int bst = 0;
    int cur = N;
    for(int i=1; i<=N; i++){
      A[i] += A[i-1];
      cur = min(cur, A[i]-i+1);
      bst = max(bst, min(cur, i));
    }
    cout << bst << endl;
  }

  return 0;
}