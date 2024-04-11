#include <bits/stdc++.h>
using namespace std;

const int k = 1<<13;

int Q;
int teiler[k];
vector<int> P;

int gcd(int a, int b){
  if(a==0)
    return b;
  return gcd(b%a, a);
}

int main(){
  for(int i=2; i*i<k; i++){
    if(teiler[i] == 0){
      P.push_back(i);
      for(int j=i; j<k; j+=i){
        if(teiler[j] == 0)
          teiler[j] = i;
      }
    }
  }
  cin >> Q;
  int a;
  for(int q=0; q<Q; q++){
    cin >> a;
    int cnt = 0;
    bool flag = true;
    for(int i=1; i<=a; i<<=1){
      flag &= (a&i) > 0;
      cnt++;
    }
    if(flag){
      bool found = false;
      for(int p : P){
        if(a%p == 0){
          cout << a/p << "\n";
          found = true;
          break;
        }
      }
      if(!found)
        cout << 1 << "\n";
    }
    else{
      cout << (1<<cnt)-1 << endl;
    }
    /*
    int best = 0;
    for(int i=1; i<a; i++){
      best = max(best, gcd(a&i, a^i));
    }
    cout << best << endl;
    cout << endl;
    */
  }

  return 0;
}