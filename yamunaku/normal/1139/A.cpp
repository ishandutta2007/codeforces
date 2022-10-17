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
  LL ans=0;
  for(int i=0;i<n;i++){
    if((s[i]-'0')%2==0){
      ans+=i+1;
    }
  }
  cout << ans << endl;
  return 0;
}