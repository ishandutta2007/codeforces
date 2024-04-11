#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, K;
int A[100];

int main(){
  cin >> N >> K;
  for(int i=0; i<N; i++){
    int x;
    cin >> x;
    A[x%K]++;
  }
  int sum = 0;
  for(int i=1; i<(K+1)/2; i++){
    sum += 2*min(A[i], A[K-i]);
  }
  sum += A[0]/2*2;
  if(K%2 == 0)
    sum += A[K/2]/2*2;

  cout << sum << endl;

  return 0;
}