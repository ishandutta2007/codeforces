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
  for(int i=0;i<n-1;i++){
    if(s[i]>s[i+1]){
      cout << "YES" << endl << i+1 SP i+2 << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}