#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main(){
  string s;
  cin >> s;
  bool foundab=0;
  bool foundba=0;
  for(int i=0;i<s.size()-1;i++){
    if(s[i]=='A'&&s[i+1]=='B'&&!foundab){
      i++;
      foundab=1;
      continue;
    }
    if(s[i]=='B'&&s[i+1]=='A'&&foundab){
      i++;
      foundba=1;
      continue;
    }
  }
  if(foundab&&foundba){
    cout << "YES" << endl;
    return 0;
  }
  foundab=0;
  foundba=0;
  for(int i=0;i<s.size()-1;i++){
    if(s[i]=='B'&&s[i+1]=='A'&&!foundba){
      i++;
      foundba=1;
      continue;
    }
    if(s[i]=='A'&&s[i+1]=='B'&&foundba){
      i++;
      foundab=1;
      continue;
    }
  }
  if(foundab&&foundba){
    cout << "YES" << endl;
    return 0;
  }
  cout << "NO" << endl;
  return 0;
}