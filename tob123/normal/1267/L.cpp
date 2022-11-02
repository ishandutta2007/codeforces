#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 1111;

int N, L, K;
string S;
int cnt[26];
string res[n];
int si;

void generate(int l, int r){
  if(sz(res[l]) == L){
    return;
  }
  if(S[si] == S[si+r-l]){
    for(int i=l; i<=r; i++){
      res[i].push_back(S[si++]);
    }
    generate(l, r);
  }
  else{
    int i;
    for(i=0; S[si+i] == S[si]; i++){
      res[l+i].push_back(S[si]);
    }
    si += i;
    generate(l+i, r);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> L >> K >> S;
  sort(S.begin(), S.end());
  generate(0, K-1);
  for(int i=0; i<N; i++){
    //cout << "extend " << res[i] << " -> ";
    while(sz(res[i]) < L){
      res[i] += S[si++];
    }
    //cout << res[i] << endl;
  }
  for(int i=0; i<N; i++){
    cout << res[i] << "\n";
  }

  return 0;
}