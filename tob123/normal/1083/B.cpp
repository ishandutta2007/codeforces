#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int n = 5e5+10;
const ll maxK = 1e10;

ll N, K;
string s, t;

ll diff[n];

int main(){
  cin >> N >> K;
  cin >> s >> t;

  diff[0] = 1;
  if(s[0] != t[0])
    diff[0]++;
  for(int i=1; i<N; i++){
    diff[i] = 2*diff[i-1];
    if('a' < s[i])
      diff[i]--;
    if('b' > t[i])
      diff[i]--;
    diff[i] = min(diff[i], maxK);
  }

  for(int i=0; i<N; i++){
    diff[i] = min(diff[i], K);
  }

  ll res = 0;
  int i;
  for(i=0; i<N; i++){
    res += diff[i];
  }

  cout << res << endl;

  return 0;
}