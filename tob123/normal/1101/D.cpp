#include <bits/stdc++.h>
using namespace std;

const int n = 2e5 + 10;

int N;
vector<int> G[n];
int A[n];
int best;
bool isprime[n];
vector<int> F[n];
map<int,int> D[n];

void calcD(int cur, int par){
  for(int x : G[cur]){
    if(x != par)
      calcD(x, cur);
  }
  for(int t : F[A[cur]]){
    int bst = 0;
    int secB = 0;
    for(int x : G[cur]){
      if(x != par){
        secB = max(secB, D[x][t]);
        if(secB > bst){
          swap(secB, bst);
        }
      }
      best = max(best, bst+secB+1);
      D[cur][t] = bst+1;
    }
  }
}

int main(){
  for(int i=2; i<n; i++){
    isprime[i] = true;
  }
  vector<int> curF;
  for(int i=2; i<n; i++){
    if(isprime[i]){
      F[i].push_back(i);
      for(int j=2*i; j<n; j+=i){
        isprime[j] = false;
        F[j].push_back(i);
      }
    }
  }

  cin >> N;
  for(int i=0; i<N; i++){
    cin >> A[i];
  }
  for(int i=0; i<N-1; i++){
    int x, y;
    cin >> x >> y;
    x--; y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }

  calcD(0, -1);
  cout << best << endl;

  return 0;
}