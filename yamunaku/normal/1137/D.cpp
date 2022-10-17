#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  int n;
  string s;
  while(1){
    cout << "next 0 1" << endl;
    cin >> n;
    for(int i=0;i<n;i++){
      cin >> s;
    }
    cout << "next 0" << endl;
    cin >> n;
    bool okflag=false;
    for(int i=0;i<n;i++){
      cin >> s;
      vector<bool> ok(10,false);
      for(int j=0;j<s.length();j++){
        ok[s[j]-'0']=true;
      }
      if(ok[0]&&ok[1]){
        okflag=true;
      }
    }
    if(okflag) break;
  }
  while(1){
    cout << "next 0 1 2 3 4 5 6 7 8 9" << endl;
    cin >> n;
    if(n==1){
      cout << "done"<< endl;
      return 0;
    }
    for(int i=0;i<n;i++){
      cin >> s;
    }
  }
  return 0;
}