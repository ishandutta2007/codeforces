#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;


int N;
vector<int> A;

int main(){
  cin >> N;
  A.resize(2*N);
  for(int i=0; i<2*N; i++){
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  if(A[0] == A[2*N-1]){
    cout << -1 << endl;
  }
  else{
    for(int x : A){
      cout << x << " ";
    }
    cout << endl;
  }

  return 0;
}