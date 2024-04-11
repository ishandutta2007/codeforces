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
  int n=s.length();
  int count=0,idx=-1;
  for(int i=0;i<n;i++){
    if(s[i]=='a') idx=i,count++;
  }
  if((n-count)%2){
    cout << ":(" << endl;
    return 0;
  }
  int x=0,y=(n-count)/2+count;
  if(y<=idx){
    cout << ":(" << endl;
    return 0;
  }
  for(int i=0;i<(n-count)/2;i++){
    while(s[x]=='a') x++;
    if(s[x]!=s[y]){
      cout << ":(" << endl;
      return 0;
    }
    x++,y++;
  }
  cout << s.substr(0,(n-count)/2+count) << endl;
  return 0;
}