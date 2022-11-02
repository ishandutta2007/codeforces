#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<ll,ll> pii;

struct line{
  bool senkr;
  ll x;
  ld t, m;
};

int N;
ll X[100001], Y[100001];
bool used[100001];
set<pii> A;

line l(int a, int b){
  line x;
  if(X[a] == X[b]){
    x.senkr = true;
    x.x = X[a];
  }
  else{
    x.senkr = false;
    x.m = Y[b]-Y[a];
    x.m /= X[b]-X[a];
    x.t = Y[a] - x.m*X[a];
  }
  return x;
}

bool same(ld a, ld b){
  return abs(a-b) < 1e-10;
}

bool isOn(line& x, int p){
  if(x.senkr){
    return X[p] == x.x;
  }
  else{
    return same(Y[p], x.m*X[p] + x.t);
  }
}

int numOf(line x){
  int cnt = 0;
  for(int i=0; i<N; i++){
    cnt += isOn(x, i);
  }
  return cnt;
}

bool existsLine(){
  vector<int> nu;
  for(int i=0; i<N; i++){
    if(!used[i])
      nu.push_back(i);
  }
  if(nu.size() <= 2)
    return true;
  line x = l(nu[0], nu[1]);
  for(int i=2; i<nu.size(); i++){
    if(!isOn(x, nu[i]))
      return false;
  }
  return true;
}

int main(){
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> X[i] >> Y[i];
    if(A.count(make_pair(X[i], Y[i]))){
      i--; N--;
    }
    else{
      A.insert(make_pair(X[i], Y[i]));
    }
  }

  if(N <= 4){
    cout << "YES" << endl;
    return 0;
  }

  for(int i=0; i<4; i++){
    for(int j=i+1; j<4; j++){
      line x = l(i, j);
      if(numOf(x) > 2){
        for(int k=0; k<N; k++){
          if(isOn(x, k)){
            used[k] = true;
          }
        }
        goto END;
      }
    }
  }
END:
  if(existsLine()){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }

  return 0;
}