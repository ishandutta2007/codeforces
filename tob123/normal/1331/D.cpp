#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string S;
  cin >> S;
  cout << (S[sz(S)-1]-'0')%2 << endl;

  return 0;
}