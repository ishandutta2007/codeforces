#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 1e6+10;

ll N;
ll A[n];
ll A2[n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  ll sum = 0;
  for(int i=0; i<N; i++){
    cin >> A[i];
    sum += A[i];
  }
  vector<ll> D;
  ll tmp = sum;
  for(ll i=2; i*i<=sum; i++){
    if(tmp%i == 0){
      D.push_back(i);
      while(tmp%i == 0)
        tmp /= i;
    }
  }
  //cout << sum << " " << tmp << endl;
  if(tmp != 1)
    D.push_back(tmp);
  if(sum == 1){
    cout << -1 << endl;
    return 0;
  }
  else if(sum == 0){
    cout << 0 << endl;
    return 0;
  }
  ll best = 2e18;
  for(ll d : D){
    //cout << d << endl;
    for(int i=0; i<N; i++){
      A2[i] = A[i] % d;
    }
    ll cur = 0;

    int firstI = 0;
    ll cnt = 0;
    int curI = 0;
    while(curI < N){
      ll ch = min(A2[curI], d-cnt);
      ll ch2 = A2[curI] - ch;
      A2[curI] = ch;
      cnt += ch;
      //indSum += ch * curI;
      if(cnt >= d){
        ll cntL=0, cntR=0;
        int pl=firstI, pr=curI;
        while(pl <= pr){
          if(cntL+A2[pl] < cntR+A2[pr]){
            cntL += A2[pl];
            pl++;
          }
          else{
            cntR += A2[pr];
            pr--;
          }
        }
        ll dest;
        if(cntL < cntR){
          dest = pl;
        }
        else
          dest = pr;
        //cout << dest << endl;
        for(int i=firstI; i<=curI; i++){
          cur += A2[i] * abs(dest-i);
        }
        A2[curI] = ch2;
        //cout << d << ", " << curI << ": " << A2[curI] << endl;
        firstI = curI;
        cnt = 0; //indSum = 0;
      }
      else{
        curI++;
      }
    }
    best = min(best, cur);
    //cout << cur << endl;
  }
  cout << best << endl;

  return 0;
}