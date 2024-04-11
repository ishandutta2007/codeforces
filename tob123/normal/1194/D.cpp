#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;

int T;
ll N, K;

int main(){
  cin >> T;
  while(T--){
    cin >> N >> K;
    if(K%3 == 0){
      N %= K+1;
      if(N == K || N%3!=0){
        cout << "Alice\n";
      }
      else{
        cout << "Bob\n";
      }
    }
    else{
      if(N%3 == 0){
        cout << "Bob\n";
      }
      else{
        cout << "Alice\n";
      }
    }
  }

  return 0;
}