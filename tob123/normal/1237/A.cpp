#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int N;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  int x = 0, a;
  for(int i=0; i<N; i++){
    cin >> a;
    if(abs(a)%2)
      x = 1-x;
    if(a < 0)
      a--;
    cout << (a+x)/2 << "\n";
  }

  return 0;
}