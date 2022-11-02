#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

string S;

int main(){
  cin >> S;
  int row1=0, row2=0;
  for(int i=0; i<S.size(); i++){
    if(S[i] == '0'){
      cout << (2*row1+1) << " " << 1 << "\n";
      row1 = 1-row1;
    }
    else{
      cout << (row2+1) << " " << 2 << "\n";
      row2 = (row2+1)%4;
    }
  }

  return 0;
}