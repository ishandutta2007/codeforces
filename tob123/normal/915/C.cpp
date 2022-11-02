#include <bits/stdc++.h>
using namespace std;

long long N;
vector<int> D;
int d=0;

long long least(int nxt){
  long long cur = nxt;
  D[nxt]--;
  for(int i=0; i<10; i++){
    for(int j=0; j<D[i]; j++){
      cur *= 10;
      cur += i;
    }
  }
  D[nxt]++;
  return cur;
}

long long pow10(int p){
  long long cur = 1;
  for(int i=0; i<p; i++)
    cur *= 10;
  return cur;
}

int main(){
  long long a;
  cin >> a;
  cin >> N;
  D.resize(10);
  for(; a>0; a/=10){
    D[a%10]++;
    d++;
  }

  for(; d>0; d--){
    int nxt = 0;
    for(int j=1; j<10; j++){
      if(D[j] > 0 && least(j) <= N){
        nxt = j;
      }
    }
    D[nxt]--;
    cout << nxt;
    N -= pow10(d-1)*nxt;
  }
  cout << endl;

  return 0;
}