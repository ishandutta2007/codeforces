#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int n = 1e5+10;

ll N;
ll B[n];
ll A[2*n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for(int i=0; i<N/2; i++){
    cin >> B[i];
  }
  ll letzt = 1e18+11;
  ll l = 0, r=1e18+10;
  for(int i=0; i<N/2; i++){
    if(B[i] < letzt){
      r = B[i]-l;
    }
    else{
      l = B[i]-r;
    }
    A[i] = l;
    A[N-i-1] = r;
    letzt = B[i];
  }

  for(int i=0; i<N; i++){
    cout << A[i] << " ";
  }
  cout << endl;

  return 0;
}