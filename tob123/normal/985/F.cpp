#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("O3")

typedef long long ll;

const ll F = 2;
const ll MOD = 1000000007;
const int maxN = 200020;

int N, M;
string S;

ll hsh[26][maxN], nxt[26][maxN], pw[maxN];

ll hs(int letter, int from, int len){
  if(from == 0)
    return hsh[letter][from+len-1];
  ll res = hsh[letter][from+len-1] - (hsh[letter][from-1] * pw[len]) % MOD;
  res += MOD;
  res %= MOD;
  return res;
}

int main(){
  /*
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  */

  cin >> N >> M;
  cin >> S;
  pw[0] = 1;
  for(int i=1; i<=N; i++){
    pw[i] = pw[i-1] * F;
    pw[i] %= MOD;
  }
  for(int i=0; i<26; i++){
    nxt[i][N-1] = S[N-1]-'a'==i ? N-1 : N;
    for(int j=N-2; j>=0; j--){
      if(S[j]-'a' == i)
        nxt[i][j] = j;
      else
        nxt[i][j] = nxt[i][j+1];
    }
  }
  hsh[S[0]-'a'][0] = 1;
  for(int i=1; i<S.size(); i++){
    for(int j=0; j<26; j++){
      hsh[j][i] = hsh[j][i-1] * F;
    }
    hsh[S[i]-'a'][i]++;
    for(int j=0; j<26; j++){
      hsh[j][i] %= MOD;
    }
  }

  vector<pair<int,int>> vx, vy;
  //vector<ll> vx, vy;
  int x, y, len;
  for(int i=0; i<M; i++){
    cin >> x >> y >> len;
    x--; y--;
    vx.clear();
    vy.clear();
    for(int j=0; j<26; j++){
      vx.push_back(make_pair(nxt[j][x], j));;
      vy.push_back(make_pair(nxt[j][y], j));;
    }
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    bool flag = true;
    for(int j=0; j<26; j++){
      if(hs(vx[j].second, x, len) != hs(vy[j].second, y, len)){
        flag = false;
        break;
      }
    }
    /*
    for(int j=0; j<26; j++){
      vx.push_back(hs(j, x, len));
      vy.push_back(hs(j, y, len));
    }
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    bool flag = true;
    for(int j=0; j<26; j++){
      if(vx[j] != vy[j])
        flag = false;
    }
    */
    if(flag){
      cout << "YES\n";
    }
    else{
      cout << "NO\n";
    }
  }

  return 0;
}