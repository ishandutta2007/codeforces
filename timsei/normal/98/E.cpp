#include <bits/stdc++.h>
using namespace std;
 
const int N = 5e3 + 5;
 
double dp[N][N];
 
int a, b;
 
bool vis[N][N];
 
double solve(int x, int y) {
  if(x == 0) return 1. / (y + 1);
  else if(y == 0) return 1;
  if(vis[x][y]) return dp[x][y];
  double a = 1 - solve(y, x - 1), b = (double)y / (y + 1) * (1 - solve(y - 1, x)), c = 1. / (y + 1) + b;
  double A = (c - b) / (1 - a + c - b), B = (1 - a) / (1 - a + c - b),
    C = (c - a) / (1 - b + c - a), D = (1 - b) / (1 - b + c - a);
  //swap(A, B); swap(C, D);
  //cerr << A <<" " << B <<' ' << C <<" " << D << endl;
  vis[x][y] = 1;
  return dp[x][y] = A * C + A * D * a + B * C * b + B * D * c;
}
 
int main() {
  cin >> a >> b;
  printf("%.12lf %.12lf\n", solve(a, b), 1 - solve(a, b));
}