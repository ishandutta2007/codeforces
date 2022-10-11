#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int r, c;
string g[200000];
string alpha = "ACGT";

void rowSolve(vector<vector<char>>& ret, string even, string odd, int& cost) {
  ret.resize(r);
  for(int i = 0; i < r; i++) {
    string match = i%2 == 0 ? even : odd;
    int normalCost = 0;
    int flipCost = 0;
    for(int j = 0; j < c; j++) {
      if(g[i][j] != match[j%2]) normalCost++;
      if(g[i][j] != match[1^(j%2)]) flipCost++;
    }
    cost += min(normalCost, flipCost);
    if(normalCost < flipCost) {
      for(int j = 0; j < c; j++) {
        ret[i].push_back(match[j%2]);
      }
    }
    else {
      for(int j = 0; j < c; j++) {
        ret[i].push_back(match[1^(j%2)]);
      }
    }
  }
}

void colSolve(vector<vector<char>>& ret, string even, string odd, int& cost) {
  ret.resize(r);
  for(int j = 0; j < c; j++) {
    string match = j%2 == 0 ? even : odd;
    int normalCost = 0;
    int flipCost = 0;
    for(int i = 0; i < r; i++) {
      if(g[i][j] != match[i%2]) normalCost++;
      if(g[i][j] != match[1^(i%2)]) flipCost++;
    }
    cost += min(normalCost, flipCost);
    if(normalCost < flipCost) {
      for(int i = 0; i < r; i++) {
        ret[i].push_back(match[i%2]);
      }
    }
    else {
      for(int i = 0; i < r; i++) {
        ret[i].push_back(match[1^(i%2)]);
      }
    }
  }
}

void solve() {
  cin >> r >> c;
  for(int i = 0; i < r; i++) {
    cin >> g[i];
  }
  vector<vector<char>> ret;
  int cost = 1e9;
  for(int aPair = 1; aPair < alpha.size(); aPair++) {
    string even = "A";
    even += alpha[aPair];
    string odd = "";
    for(int i = 1; i < 4; i++) {
      if(i != aPair) odd += alpha[i];
    }
    {
      int currCost = 0;
      vector<vector<char>> cand;
      rowSolve(cand, even, odd, currCost);
      if(currCost < cost) {
        ret = cand;
        cost = currCost;
      }
    }
    {
      int currCost = 0;
      vector<vector<char>> cand;
      rowSolve(cand, odd, even, currCost);
      if(currCost < cost) {
        ret = cand;
        cost = currCost;
      }
    }
    {
      int currCost = 0;
      vector<vector<char>> cand;
      colSolve(cand, even, odd, currCost);
      if(currCost < cost) {
        ret = cand;
        cost = currCost;
      }
    }
    {
      int currCost = 0;
      vector<vector<char>> cand;
      colSolve(cand, odd, even, currCost);
      if(currCost < cost) {
        ret = cand;
        cost = currCost;
      }
    }
  }
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      cout << ret[i][j];
    }
    cout << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}