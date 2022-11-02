#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;

int Q;
string S, T, P;
int cnt[26];

int main(){
  cin >> Q;
  while(Q--){
    cin >> S >> T >> P;
    for(int i=0; i<26; i++)
      cnt[i] = 0;
    for(char c : P){
      cnt[c-'a']++;
    }
    int si = 0;
    bool pos = true;
    for(int i=0; i<sz(T); i++){
      if(si <= sz(S) && S[si] == T[i]){
        si++;
      }
      else{
        if(cnt[T[i]-'a'] > 0){
          cnt[T[i]-'a']--;
        }
        else{
          pos = false;
          break;
        }
      }
    }
    if(pos && si==sz(S)){
      cout << "YES\n";
    }
    else{
      cout << "NO\n";
    }
  }

  return 0;
}