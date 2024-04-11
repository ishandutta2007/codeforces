#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define f first
#define s second
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define mp make_pair
typedef long double ld;
typedef gp_hash_table<int, null_type, hash<int>> ht;
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 
const int MX = 2e5 + 5;
int main() {
  int t; cin >> t;
  while(t--) {
    int n, U, R, D, L; cin >> n >> U >> R >> D >> L;
    int a = 0, b = 0, c = 0, d = 0;
    if(U >= n-1) a+=U-n+2;
    if(R >= n-1) b+=R-n+2;
    if(D >= n-1) c+=D-n+2;
    if(L >= n-1) d+=L-n+2;
    int x = (a==2)+(c==2);
    int y = (b==2)+(d==2);
    if((min(R, 2) + min(L, 2) < a + c) || min(R, L) < x) cout << "NO" << "\n";
    else if((min(U, 2) + min(D, 2) < b + d) || min(U, D) < y) cout << "NO" << "\n";
    else cout << "YES" << "\n";

  }
}