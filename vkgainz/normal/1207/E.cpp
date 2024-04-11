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
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 
const int MX = 1e5 + 5;

int main() {
  vector<int> v;
  for(int i=1;i<=100;i++) v.push_back(i);
  cout << "? " << " ";
  for(auto &v : v) cout << v << " ";
  cout << "\n";
  cout.flush();
  int L1; cin >> L1;
  for(int i=0;i<100;i++) v[i]*=128;
  cout << "? " << " ";
  for(auto &v : v) cout << v << " ";
  cout << "\n";
  cout.flush();
  int L2; cin >> L2;
  int y = L1^L2;
  int a = y%128;
  cout << "! " << (L1^a) << "\n";
}