#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define mp make_pair
const int MX = 1e5+5;
bool cmp(int &x, int &y) {
  return abs(x) < abs(y);
}
int main() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<int> x, y;
    for(int i=0;i<2*n;i++) {
      int a, b; cin >> a >> b;
      if(a == 0) x.push_back(b);
      else y.push_back(a);
    }
    sort(x.begin(), x.end(), cmp);
    sort(y.begin(), y.end(), cmp);
    double ans = 0.0;
    for(int i=0;i<n;i++) {
      ans += sqrt(x[i]*1.0*x[i] + y[i]*1.0*y[i]);
    }
    cout << setprecision(24) << ans << "\n";
  }
}