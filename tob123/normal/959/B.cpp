#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 10000000000000000ll;

int N, K, m;
string W[100000];
map<string, ll> M;
ll C[100000], MC[100000], G[100000];

void printAll(){
  for(int i=0; i<K; i++){
    cout << MC[i] << " ";
  }
  cout << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin >> N >> K >> m;
  for(int i=0; i<N; i++){
    cin >> W[i];
    M[W[i]] = i;
  }
  for(int i=0; i<N; i++){
    cin >> C[i];
  }
  for(int i=0; i<K; i++){
    int n;
    cin >> n;
    MC[i] = INF;
    for(int j=0; j<n; j++){
      int a;
      cin >> a;
      a--;
      G[a] = i;
      MC[i] = min(MC[i], C[a]);
    }
  }

  //printAll();

  long long res = 0;
  for(int i=0; i<m; i++){
    string w;
    cin >> w;
    res += MC[G[M[w]]];
  }
  cout << res << endl;

  return 0;
}