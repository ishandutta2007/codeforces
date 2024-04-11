#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define mp make_pair
const int MX = 3e6+5;
int main() {
  int t; cin >> t;
  while(t--) {
    int A, B; cin >> A >> B;
    if(B==1) {
      cout << "NO" << "\n";
      continue;
    }
    cout << "YES" << "\n";
    cout << A*1LL*(B-1) << " " << A*1LL*(B+1) << " " << A*1LL*(2*B) << "\n";
  }
}