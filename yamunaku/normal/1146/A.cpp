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
  string s;
  cin >> s;
  int count=0;
  for(int i=0;i<s.length();i++){
    if(s[i]=='a') count++;
  }
  for(int i=s.length();i>=0;i--){
    if(count*2>i){
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}