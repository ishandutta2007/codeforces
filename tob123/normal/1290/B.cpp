#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 2e5+10;

int N, Q;
string S;
int cnt[26][n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> S;
  N = sz(S);
  for(int i=0; i<26; i++){
    for(int j=0; j<=N; j++){
      cnt[i][j] = 0;
    }
  }
  for(int i=0; i<sz(S); i++){
    cnt[S[i]-'a'][i+1]++;
  }
  for(int i=0; i<26; i++){
    for(int j=1; j<=N; j++){
      cnt[i][j] += cnt[i][j-1];
    }
  }
  cin >> Q;
  for(int i=0; i<Q; i++){
    int l, r;
    cin >> l >> r;
    bool pos = l == r || S[l-1] != S[r-1];
    int x = 0;
    for(int i=0; i<26; i++){
      if(cnt[i][r]-cnt[i][l-1])
        x++;
    }
    pos |= x > 2;
    cout << (pos ? "Yes" : "No") << "\n";
  }

  return 0;
}