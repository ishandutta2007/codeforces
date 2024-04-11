#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;
const double EPS = 1e-6;

struct Target{
  int x;
  int y;
  int t;
  double p;
};

bool operator<(const Target& t1, const Target& t2){
  return t1.t < t2.t;
}

int N;
bool g[1000][1000];

int main(){
  memset(g, sizeof(g), 0);
  cin >> N;
  int x, y, t;
  double p;
  vector<Target> target;
  for(int i = 0; i < N; ++i){
    cin >> x >> y >> t >> p;
    Target tar;
    tar.x = x;
    tar.y = y;
    tar.t = t;
    tar.p = p;
    target.push_back(tar);
  }
  sort(target.begin(), target.end());
  for(int i = 0; i < N; ++i){
    Target& t1 = target[i];
    //cout << t1.t << endl;
    for(int j = i+1; j < N; ++j){
      Target& t2 = target[j];
      double d = sqrt((t1.x-t2.x)*(t1.x-t2.x) + (t1.y-t2.y)*(t1.y-t2.y));
       if(d <= t2.t - t1.t){
    g[i][j] = true;
    //cout << i << "," << j << endl;
      }
    }
  }
  vector<double> dp(N);
  for(int i = 0; i < N; ++i){
    double m = target[i].p;
    for(int j = 0; j < i; ++j){
      if(g[j][i]){
    m = max(m, dp[j] + target[i].p);
      }
    }
    dp[i] = m;
  }
  double ans = 0;
  for(int i = 0; i < N; ++i){
    ans = max(ans, dp[i]);
  }
  printf("%f", ans);
  //cout << ans;
  return 0;
}