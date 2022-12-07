#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  char s;
  cin >> N >> K;
  vector<int> S(N);
  vector<int> S_new(N);
  for (int i=0; i < N; i++) {
      cin >> s;
      if (s=='R') {
          S.at(i) = 1;
      }
      else {
          S.at(i) = 0;
      }
  }
  
  vector<vector<int>> ans(0);
  int updated = 0;
  int cnt = 0;
  while (true) {
      updated = 0;
    vector<int> ans_tmp(0);
      for (int i=0; i < N; i++) {
          if (i == N-1) {
              S_new.at(i) = S.at(i);
              continue;
          }
          if (S.at(i) == 1 && S.at(i+1) == 0) {
              S_new.at(i) = 0;
              S_new.at(i+1) = 1;
              ans_tmp.push_back(i);
              cnt++;
              i++;
              updated = 1;
          }
          else {
              S_new.at(i) = S.at(i);
          }
      }
      if (!updated) {
          break;
      }
      S = S_new;
      ans.push_back(ans_tmp);
  }
  if (cnt < K || K < ans.size()) {
    cout << -1 << "\n";
  }
  else {
    int L;
    int i=0;
    L = ans.size();
    while (true) {
      vector<int> line = ans.at(i);
      int l = line.size() - 1;
      if (K > L) {
        cout << 1 << " " << line.at(l)+1 << "\n";
        ans.at(i).pop_back();
        K--;
        if (l == 0) {
          i++;
          L--;
          continue;
        }
        
      }
      else {
        if (line.size() != 0) {
          cout << line.size() << " ";
          for (int j=0; j < line.size(); j++) {
            cout << line.at(j)+1 << " ";
          }
        cout << "\n";
        i++;
        break;
        }
    }
    
      }
    for (i;i < ans.size();i++) {
      vector<int> line = ans.at(i);
      cout << line.size() << " ";
      for (int j=0; j < line.size(); j++) {
        cout << line.at(j)+1 << " ";
      }  
      cout << "\n";
      
    }
  }
}