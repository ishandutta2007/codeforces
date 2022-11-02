#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;

int N, M;
string S, x;
vector<int> R[26];

int main(){
  cin >> N;
  cin >> S;
  for(int i=0; i<N; i++){
    R[S[i]-'a'].push_back(i);
  }
  cin >> M;
  for(int i=0; i<M; i++){
    cin >> x;
    vector<int> cur(26, 0);
    int res = 0;
    for(char c : x){
      res = max(res, R[c-'a'][cur[c-'a']]);
      cur[c-'a']++;
    }
    cout << res+1 << "\n";
  }

  return 0;
}