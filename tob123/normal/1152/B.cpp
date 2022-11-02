#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int x;

int main(){
  cin >> x;
  vector<int> r;
  for(int i=0; i<20; i++){
    if(x & (1<<i)){
      r.push_back(i);
      x += (1<<i) - 1;
      if(i<20)
        x++;
    }
  }
  cout << r.size()*2-1 << endl;
  for(int a : r){
    cout << a << " ";
  }
  cout << endl;

  return 0;
}