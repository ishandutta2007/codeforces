#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int T, N, K;
string S;
int cnt[26];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> N >> K >> S;
    int res = 0;
    //cerr << S << endl;
    for(int i=0; i<K/2; i++){
      for(int j=0; j<26; j++){
        cnt[j] = 0;
      }
      for(int x=0; x<N/K; x++){
        cnt[S[K*x+i]-'a']++;
        cnt[S[K*(x+1)-i-1]-'a']++;
      }
      int sum = 0;
      int best = 0;
      for(int j=0; j<26; j++){
        sum += cnt[j];
        best = max(best, cnt[j]);
      }
      //cerr << sum << " " << best << endl;
      res += sum-best;
    }
    if(K%2){
      for(int j=0; j<26; j++){
        cnt[j] = 0;
      }
      for(int x=0; x<N/K; x++){
        cnt[S[K*x+K/2]-'a']++;
      }
      int sum = 0;
      int best = 0;
      for(int j=0; j<26; j++){
        sum += cnt[j];
        best = max(best, cnt[j]);
      }
      res += sum-best;
      //cerr << sum << " " << best << endl;
    }
    cout << res << "\n";
  }

  return 0;
}