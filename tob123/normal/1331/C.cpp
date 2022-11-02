#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int x;
  vector<int> v = {4, 1, 3, 2, 0, 5};
  cin >> x;
  int res = 0;
  for(int i=0; i<6; i++){
    if(x & (1<<i))
      res |= 1<<v[i];
  }
  cout << res << endl;

  return 0;
}