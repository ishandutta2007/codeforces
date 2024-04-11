#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e12;
const ll n = 1e5+2;

ll N, S;
ll L[n];
ll sum;
ll chCnt[n];
int cur;
int par[n];

ll low(ll verz){
  ll sum = 0;
  ll pw = 1;
  ll cnt = 1;
  ll miss = N;
  while(miss > 0){
    if(miss >= cnt){
      miss -= cnt;
      sum += cnt*pw;
      cnt *= verz;
      pw++;
    }
    else{
      sum += pw*miss;
      miss = 0ll;
    }
  }
  return sum;
}

int main(){
  cin >> N >> S;
  if(S == N*(N+1)/2){
    cout << "Yes" << endl;
    for(int i=1; i<N; i++){
      cout << i << " ";
    }
    cout << endl;
    return 0;
  }
  /*
  for(int i=2; i<N; i++){
    cout << low(i) << " ";
  }
  cout << endl;
  */
  ll l=2, r=N-1;
  while(l < r){
    ll m = (l+r)/2;
    if(low(m) <= S){
      r = m;
    }
    else{
      l = m+1;
    }
  }
  if(low(l) > S){
    cout << "No" << endl;
    return 0;
  }
  else{
    ll pow = 1;
    ll cntCur = 0;
    ll curL = 1;
    for(ll i=0; i<N; i++){
      L[curL]++;
      sum += curL;
      cntCur++;
      if(cntCur == pow){
        pow *= l;
        curL++;
        cntCur = 0;
      }
    }
    ll maxL = curL;
    if(L[maxL] == 0)
      maxL--;
    for(ll i=maxL; i>0; i--){
      while(sum < S && L[i] > 1){
        L[i]--;
        if(S-sum >= maxL+1-i){
          maxL++;
          sum += maxL-i;
          L[maxL]++;
        }
        else{
          ll newL = i + S-sum;
          L[newL]++;
          sum = S;
        }
      }
    }
    if(sum < S){
      cout << "No" << endl;
      return 0;
    }
    cout << "Yes" << endl;
    cur = N;
    vector<int> C, C2;
    int cntN = 0;
    for(int i=maxL+1; i>0; i--){
      int X = 0;
      cntN += L[i];
      for(int j=0; j<L[i]; j++){
        //cout << cur << "..." << endl;
        while(X < C.size() && chCnt[cur] < l){
          chCnt[cur]++;
          par[C[X]] = cur;
          X++;
        }
        C2.push_back(cur);
        cur--;
      }
      C = C2;
      C2.clear();
    }
    for(int i=2; i<=N; i++){
      cout << par[i] << " ";
    }
    cout << endl;
    /*
    for(int i=0; i<=maxL; i++){
      cout << i << ": " << L[i] << endl;
    }
    */
  }

  return 0;
}