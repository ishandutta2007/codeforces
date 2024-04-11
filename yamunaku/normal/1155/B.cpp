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
  cin >> n;
  string s;
  cin >> s;
  int k=(n-11)/2;
  vector<bool> er(n,false);
  int c=0;
  for(int i=0;i<n;i++){
    if(s[i]!='8'){
      if(c<k){
        c++;
        er[i]=true;
      }else{
        break;
      }
    }
  }
  c=0;
  for(int i=0;i<n;i++){
    if(c>k) break;
    if(s[i]!='8'){
      if(!er[i]){
        cout << "NO" << endl;
        return 0;
      }
    }else{
      c++;
    }
  }
  cout << "YES" << endl;
  return 0;
}