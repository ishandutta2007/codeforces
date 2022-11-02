#include <bits/stdc++.h>
using namespace std;

string S;

int type(char c){
  switch(c){
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
      return 2;
    case 'n':
      return 1;
    default:
      return 0;
  }
}

int main(){
  cin >> S;
  bool val = true;
  for(int i=0; i<S.length()-1; i++){
    if(type(S[i]) == 0 && type(S[i+1]) != 2){
      val = false;
      break;
    }
  }
  val &= type(S[S.length()-1]) != 0;

  if(val){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }

  return 0;
}