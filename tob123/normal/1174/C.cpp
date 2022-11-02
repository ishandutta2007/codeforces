#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;

const int n = 1e5+10;

int N;
bool p[n];
int A[n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  int cnt = 1;
  for(ll i=2; i<=N; i++){
    if(!p[i]){
      A[i] = cnt;
      for(ll j=i*i; j<=N; j+=i){
        p[j] = true;
        A[j] = cnt;
      }
      cnt++;
    }
  }
  for(int i=2; i<=N; i++){
    cout << A[i] << " ";
  }
  cout << endl;

  return 0;
}