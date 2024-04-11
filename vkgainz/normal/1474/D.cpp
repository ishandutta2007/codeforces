#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree <pair<ll, int>, null_type, less<pair<ll, int>>, rb_tree_tag, tree_order_statistics_node_update>
typedef long long ll;
typedef long double ld;
#define f first
#define s second
const int MX = 3e5 + 5;

int main() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    vector<ll> b(n);
    b[0] = a[0];
    for(int i=1;i<n;i++) {
      b[i] = -b[i-1] + a[i];
    }
    bool work = true;
    for(int i=0;i<n;i++) {
      if(b[i] >=0) continue;
      work = false;
    }
    work = work&&(b[n-1]==0);
    if(work) {
      cout << "YES" << "\n";
      continue;
    }
    //a[0], a[1] - a[0], a[2]+a[0]-a[1],...
    //when swap a[i], a[i+1]
    //val[i] += a[i+1]-a[i]
    //val[i+1] -= 2*(a[i+1]-a[i])
    //val[i+2] += 2*(a[i+1]-a[i])
    // get minimum of val[i+2], val[i+4],... check if that +2*(a[i+1]-a[i]) >=0
    // get minimum of val[i+1], val[i+3], ... check if that -2*(a[i+1]-a[i]) >=0
    // check if val[i] + (a[i+1] - a[i]) >= 0
    // check if val[n-1] = 0 (do odd or even check)
    vector<ll> sufomin(n), sufemin(n);
    for(int i=n-1;i>=0;i--) {
      if(i==n-1) {
        if(i%2) sufomin[i] = b[i], sufemin[i] = 1e12;
        else sufomin[i] = 1e12, sufemin[i] = b[i];
      }
      else {
        sufomin[i] = sufomin[i+1], sufemin[i] = sufemin[i+1];
        if(i%2) sufomin[i] = min(sufomin[i], b[i]);
        else sufemin[i] = min(sufemin[i], b[i]);
      }
    }
    for(int i=0;i<n-1 && !work;i++) {
      //swap(a[i], a[i+1])
      int x = a[i+1]-a[i];
      bool tempwork = true;
      if(b[i] + x < 0) tempwork = false;
      ll r = sufemin[i+1];
      ll s = sufomin[i+1];
      if(i%2) {
        tempwork = tempwork&&(r-2*x >=0);
        tempwork = tempwork&&(s+2*x >=0);
      }
      else {
        tempwork = tempwork&&(r+2*x >=0);
        tempwork = tempwork&&(s-2*x >=0);
      }
      if((n-i-1)%2) {
        tempwork = tempwork&&(b[n-1]-2*x == 0);
      }
      else {
        tempwork = tempwork&&(b[n-1]+2*x == 0);
      }
      work = work|tempwork;
      if(b[i]<0) break;
    }
    if(work) cout << "YES" << "\n";
    else cout << "NO" << "\n";
  }
}