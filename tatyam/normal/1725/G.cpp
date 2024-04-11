#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  long long tv = 10000000000, fv = 0;
  while (tv - fv > 1){
    long long mid = (tv + fv) / 2;
    long long S = 0;
    if (mid >= 3){
      S += (mid - 1) / 2;
    }
    if (mid >= 8){
      S += mid / 4 - 1;
    }
    if (S >= N){
      tv = mid;
    } else {
      fv = mid;
    }
  }
  cout << tv << endl;
}