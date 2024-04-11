#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

#define max(a,b) ((a>b)?(a):(b))
#define min(a,b) ((a<b)?(a):(b))

int main(){
  string s;
  cin >> s;
  int link=0,pearl=0;
  for(int i=0;i<s.length();i++){
    if(s[i]=='o'){
      pearl++;
    }else if(s[i]=='-'){
      link++;
    }
  }
  if(pearl==0){
    cout << "YES" << endl;
    return 0;
  }
  if(link%pearl){
    cout << "NO" << endl;
  }else{
    cout << "YES" << endl;
  }
  return 0;
}