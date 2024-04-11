#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> L(N), R(N);
  for (int i = 0; i < N; i++){
    cin >> L[i] >> R[i];
    L[i]--;
  }
  vector<int> ans(30, 0);
  for (int i = 0; i < 30; i++){
    vector<int> L2, R2;
    int M = 0;
    for (int j = 0; j < N; j++){
      if (R[j] - L[j] < (1 << i)){
        L2.push_back(L[j] % (1 << i));
        R2.push_back(R[j] % (1 << i));
        M++;
      }
    }
    vector<int> X;
    for (int j = 0; j < M; j++){
      X.push_back(L2[j]);
      X.push_back(R2[j]);
    }
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    for (int j = 0; j < M; j++){
      L2[j] = lower_bound(X.begin(), X.end(), L2[j]) - X.begin();
      R2[j] = lower_bound(X.begin(), X.end(), R2[j]) - X.begin();
    }
    int cnt = X.size();
    vector<int> imos(cnt + 1, 0);
    for (int j = 0; j < M; j++){
      if (L2[j] < R2[j]){
        imos[L2[j]]++;
        imos[R2[j]]--;
      } else {
        imos[L2[j]]++;
        imos[cnt]--;
        imos[0]++;
        imos[R2[j]]--;
      }
    }
    for (int j = 0; j < cnt; j++){
      imos[j + 1] += imos[j];
    }
    ans[i] = N - M;
    for (int j = 0; j < cnt; j++){
      ans[i] = max(ans[i], imos[j] + (N - M));
    }
  }
  int Q;
  cin >> Q;
  for (int i = 0; i < Q;  i++){
    int W;
    cin >> W;
    for (int j = 0; j < 30; j++){
      if ((W >> j & 1) == 1){
        cout << ans[j] << "\n";
        break;
      }
    }
  }
}