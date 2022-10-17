#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);ios_base::sync_with_stdio(0);
  
  string inp; cin>>inp;
  int moves; cin>>moves;
  
  int pointer = 0, max, minus;
  while (moves && pointer < inp.size()){
    max = inp[pointer], minus = 0;
    for (int i = pointer + 1; i < pointer + 1 + moves && i < inp.size(); i++) {
      if (inp[i] > max){
        max = inp[i];
        minus = i - pointer;
      }
    }
    moves -= minus;
    for(int i = pointer + minus; i > pointer; i--){
      swap(inp[i], inp[i-1]);
    }
    // cout<<"moves left : "<<moves<<endl;
    // cout<<"swapped : "<<pointer<<pointer+minus<<endl;
    // cout<<"now inp : "<<inp<<endl;
    pointer++;
  }
  // cout<<"Ans is : "<<endl;
  cout<<inp<<endl;
}