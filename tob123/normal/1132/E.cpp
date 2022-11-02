#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll W;
ll C[2000];
ll best;

void solve2(ll cur){
  ll lim, nxt, nxtCur;
  if(cur == 5){
    lim = 6;
    nxt = 5*6;
    nxtCur = cur+1;
  }
  else if(cur == 6){
    lim = 5;
    nxt = 5*6;
    nxtCur = cur+1;
  }
  else if(cur == 7){
    lim = 8;
    nxt = 7*8;
    nxtCur = cur+1;
  }
  else if(cur == 8){
    lim = 7;
    nxt = 7*8;
    nxtCur = 30;
  }
  else if(cur == 30){
    lim = 56;
    nxt = 5*6*7*8;
    nxtCur = 56;
  }
  else if(cur == 56){
    lim = 30;
    nxt = 5*6*7*8;
    nxtCur = 5*6*7*8;
  }
  else{ //cur == 30*56
    if(W >= 0){
      if(W-C[cur]*cur >= 0){
        best = min(best, W-C[cur]*cur);
      }
      else{
        best = min(best, W%cur);
      }
    }
    return;
  }
  for(ll i=0; i<=min(lim-1, C[cur]); i++){
    ll x = (C[cur]-i)/lim;
    W -= i*cur;
    C[nxt] += x;
    solve2(nxtCur);
    C[nxt] -= x;
    W += i*cur;
  }
}

void solve1(ll cur){
  if(cur == 5)
    solve2(cur);
  else if(C[cur]){
    ll x = C[cur]/2;
    C[cur*2] += x;
    solve1(cur+1);
    C[cur*2] -= x;

    W -= cur;
    C[cur]--;
    C[cur*2] += C[cur]/2;
    solve1(cur+1);
    C[cur*2] -= C[cur]/2;
    C[cur]++;
    W += cur;
  }
  else{
    solve1(cur+1);
  }
}

int main(){
  cin >> W;
  best = W;
  for(int i=1; i<=8; i++){
    cin >> C[i];
  }

  solve1(1);

  /*
  cout << W << endl;
  cout << best << endl;
  */
  cout << W-best << endl;

  return 0;
}