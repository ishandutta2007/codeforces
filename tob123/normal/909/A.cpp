#include <bits/stdc++.h>
using namespace std;


int main(){
  string v, n;
  cin >> v >> n;
  cout << v[0];
  for(int i=1; i<v.size(); i++){
    if(v[i] >= n[0])
      break;
    cout << v[i];
  }
  cout << n[0] << endl;

  return 0;
}