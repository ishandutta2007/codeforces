#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;

int N;
vector<int> A;

int main(){
  cin >> N;
  A.resize(N);
  bool odd=false, even=false;
  for(int i=0; i<N; i++){
    cin >> A[i];
    if(A[i]%2){
      odd = true;
    }
    else
      even = true;
  }
  if(odd && even){
    sort(A.begin(), A.end());
  }
  for(int x : A){
    cout << x << " ";
  }
  cout << endl;

  return 0;
}