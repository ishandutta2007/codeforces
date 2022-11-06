#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int n, t, m, p;
long  double c;
const int maxn = 2* (int)1e5;
long double src[maxn + 123];
long double real[maxn + 123];
long double fake[maxn + 123];

void solve() {
 cin >> n >> t >> c;
 for (int i = 1; i <= n; ++i) {
  cin >> src[i];
 }
 real[t] = 0.0;
 for (int i = 1; i <= t; ++i){ 
  real[t] += src[i];
 }  
 for (int i = t + 1; i <= n; ++i) {
  real[i] = real[i-1] - src[i-t] + src[i];
 }
 for (int i = t; i <= n; ++i) {
  real[i] /= (t * 1.0);
 }
 fake[0] = 0.0;
 for (int i = 1; i <= n; ++i) {
  fake[i] = (fake[i-1] + src[i]/t)/c;
 }
 cin >> m;
 cout << setprecision(10) << fixed;
 for (int i = 0; i < m; ++i) {
  cin >> p;
  cout << real[p] << " " << fake[p] << " " << abs(fake[p] - real[p]) / real[p] << "\n";
 }
}

int main () {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 solve();
 return 0;
}