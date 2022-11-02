#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, M, K;
vector<int> A;
vector<pair<int,int>> B;
bool used[200010];

int main(){
  cin >> N >> M >> K;
  A.resize(N);
  B.resize(N);
  for(int i=0; i<N; i++){
    cin >> A[i];
    B[i].first = A[i];
    B[i].second = i;
  }
  sort(B.rbegin(), B.rend());
  
  ll res = 0;
  for(int i=0; i<M*K; i++){
    res += B[i].first;
    used[B[i].second] = true;
  }

  cout << res << endl;
  int cnt = 0;
  int ges = 1;
  for(int i=0; i<N; i++){
    if(used[i]){
      //cout << i+1 << " ";
      cnt++;
      if(cnt == M && ges != K){
        ges++;
        cnt = 0;
        cout << i+1 << " ";
      }
    }
  }

  cout << endl;

  return 0;
}