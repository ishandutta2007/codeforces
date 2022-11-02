#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;

int T, N;
string s;

int main(){
  cin >> T;
  for(int t=1; t<=T; t++){
    cin >> N;
    cin >> s;
    bool f = false;
    for(int i=0; i<N-10; i++){
      f |= s[i] == '8';
    }
    cout << (f ? "YES" : "NO") << endl;
  }

  return 0;
}