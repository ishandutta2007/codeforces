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
  cin >> n >> s;
  if(n%2){
    cout << ":(" << endl;
    return 0;
  }
  if(s[0]==')'||s[n-1]=='('){
    cout << ":(" << endl;
    return 0;
  }
  s[0]='(',s[n-1]=')';
  int x=0;
  int k=(n-2)/2;
  for(int i=1;i<n-1;i++){
    if(s[i]=='(') k--;
  }
  for(int i=1;i<n-1;i++){
    if(s[i]=='(') x++;
    else if(s[i]==')') x--;
    else{
      if(k>0) x++,s[i]='(',k--;
      else x--,s[i]=')';
    }
    if(x<0){
      cout << ":(" << endl;
      return 0;
    }
  }
  if(x==0) cout << s << endl;
  else cout << ":(" << endl;
  return 0;
}