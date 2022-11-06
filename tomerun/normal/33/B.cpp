#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <cstdio>
#include <cmath>
//#include "../myutil.hpp"

using namespace std;
const int INF = 1000000000;


int g[26][26];
string a,b;

int main(){
  for(int i = 0; i < 26; ++i) {
    for (int j = 0; j < 26; ++j) {
      g[i][j] = INF;
    }
  }
  for (int i = 0; i < 26; ++i) {
    g[i][i] = 0;
  }
  cin >> a >> b;
  if (a.size() != b.size()) {
    cout << -1;
    return 0;
  }
  int n;
  cin >> n;
  char A,B;
  int W;
  for (int i = 0; i < n; ++i) {
    cin >> A >> B >> W;
    g[A - 'a'][B - 'a'] = min(g[A - 'a'][B - 'a'], W);
  }
  for(int k = 0; k < 26; ++k) {
    for (int i = 0; i < 26; ++i) {
      for(int j = 0; j < 26; ++j) {
    if (g[i][k] != INF && g[k][j] != INF && g[i][j] > g[i][k] + g[k][j]) {
      g[i][j] = g[i][k] + g[k][j];
    }
      }
    }
  }
  std::string result;
  int ans = 0;
  for (int i = 0; i < a.size(); ++i){
    int ai = a[i] - 'a';
    int bi = b[i] - 'a';
    int cost = INF;
    char resChar = 'a';
    for(int j = 0; j < 26; ++j) {
      int costA = g[ai][j];
      int costB = g[bi][j];
      if(costA + costB < cost) {
    cost = costA + costB;
    resChar = (char)(j + 'a');
      }
    }
    if(cost == INF) {
      cout << -1;
      return 0;
    }
    result.push_back(resChar);
    ans += cost;
  }
  cout << ans << endl;
  cout << result;
  return 0;
}