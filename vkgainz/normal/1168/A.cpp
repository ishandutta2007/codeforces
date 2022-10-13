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

int main() {
  int n, m; cin >>n >> m;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  int lo = 0, hi = m + 1; //[lo, hi]
  for(int i=0;i<20;i++) {
    int mid = (lo+hi)/2;
    int lst = 0;
    bool work = true;
    for(int j=0;j<n && work;j++) {
      if(a[j] <= lst) {
        if(lst-a[j] > mid) {
          work = false;
        }
      }
      else {
        if(m+lst-a[j] > mid) {
          lst = a[j];
        }
      }
    }
    if(work) {
      hi = mid;
    }
    else {
      lo = mid + 1;
    }
  }
  cout <<lo << "\n";
}