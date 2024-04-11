#include <bits/stdc++.h>
using namespace std;

const int n = 100100;
int N;
bool vis[n+2];
int nxt[n+2];
set<int> S;

set<int> used;

void zerlege(){
  for(int i=2; i<n; i++){
    if(!vis[i]){
      for(int j=1; j*i < n; j++){
        nxt[j*i] = j;
        vis[j*i] = true;
      }
    }
  }
}

int findNext(int cur){
  int x = *S.lower_bound(cur);
  vector<int> primes;
  int a = x;
  while(a != 1){
    primes.push_back(a / nxt[a]);
    a = nxt[a];
  }
  for(int p : primes){
    if(!vis[p]){
      vis[p] = true;
      used.insert(p);
      for(int j=1; j*p < n; j++){
        S.erase(j*p);
      }
    }
  }
  return x;
}


bool s[3000000];
void printPrimes(int n){
  for(int i=2; i<3000000; i++){
    if(!s[i]){
      for(int j=1; j*i < 3000000; j++){
        s[j*i] = true;
      }
      if(!used.count(i)){
        cout << i << " ";
        n--;
        if(n == 0)
          return;
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin >> N;
  for(int i=1; i<n; i++){
    S.insert(i);
  }
  zerlege();
  for(int i=2; i<=n; i++){
    vis[i] = false;
  }
  vis[1] = true;

  for(int i=0; i<N; i++){
    int x;
    cin >> x;
    int out = findNext(max(2, x));
    cout << out << " ";
    if(out > x){
      printPrimes(N-i-1);
      break;
    }
  }
  cout << endl;

  return 0;
}