#include <bits/stdc++.h>
using namespace std;

int N;

int main(){
  cin >> N;
  int curM = 1000000001;
  bool val = true;
  for(int i=0; i<N; i++){
    int a, b;
    cin >> a >> b;
    if(max(a, b) <= curM)
      curM = max(a, b);
    else if(min(a, b) <= curM)
      curM = min(a, b);
    else{
      val = false;
      break;
    }
  }
  if(val)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}