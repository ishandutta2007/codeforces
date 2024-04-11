#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;

const int n = 5e5+10;

int N, M;
int C[n], S[n];
vector<int> U[n];
bool used[n];

int find(int x){
  if(C[x] == x)
    return x;
  else{
    C[x] = find(C[x]);
    return C[x];
  }
}

void comb(int a, int b){
  a = find(a);
  b = find(b);
  if(a != b){
    C[b] = a;
    S[a] += S[b];
  }
}

int main(){
  cin >> N >> M;
  for(int i=0; i<M; i++){
    int k, x;
    cin >> k;
    for(int j=0; j<k; j++){
      cin >> x;
      x--;
      U[x].push_back(i);
      if(!used[x]){
        used[x] = true;
        S[i]++;
      }
    }
    C[i] = i;
  }

  for(int i=0; i<N; i++){
    for(int x : U[i]){
      comb(U[i][0], x);
    }
  }

  for(int i=0; i<N; i++){
    if(sz(U[i]) == 0)
      cout << 1 << " ";
    else
      cout << S[find(U[i][0])] << " ";
  }
  cout << endl;

  return 0;
}