#include <bits/stdc++.h>
using namespace std;

int T;
string s;

int main(){
  cin >> T;
  while(T--){
    cin >> s;
    bool pos = false;
    for(int i=0; i<s.size()-1; i++){
      if(s[i] != s[i+1]){
        pos = true;
      }
    }
    if(!pos){
      cout << -1 << endl;
    }
    else{
      sort(s.begin(), s.end());
      cout << s << endl;
    }
  }

  return 0;
}