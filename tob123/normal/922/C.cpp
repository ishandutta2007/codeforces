#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

ull N, K;

bool primePower(ull x){
  bool flag = false;
  for(int i=2; i<=x; i++){
    if(x%i == 0){
      while(x%i == 0)
        x /= i;
      if(flag)
        return false;
      flag = true;
    }
  }
  cout << x << endl;
  return true;
}

int main(){
  cin >> N >> K;
  if(K >= 1000){
    cout << "NO" << endl;
    return 0;
  }
  /*
  for(int i=0; i<1000; i++){
    primePower(i);
  }
  */
  for(ull i=1; i<=K && i<1000; i++){
    if(N % i != i-1){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;

  return 0;
}