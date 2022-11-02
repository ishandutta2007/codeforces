#include <bits/stdc++.h>
using namespace std;

int N;
string s;
set<char> vovel;

int main(){
  cin >> N;
  cin >> s;

  vovel.insert('a');
  vovel.insert('e');
  vovel.insert('i');
  vovel.insert('o');
  vovel.insert('u');
  vovel.insert('y');

  bool pref = false;
  for(int i=0; i<N; i++){
    if(!pref || vovel.count(s[i])==0){
      cout << s[i];
    }
    if(vovel.count(s[i])){
      pref = true;
    }
    else{
      pref = false;
    }
  }
  cout << endl;

  return 0;
}