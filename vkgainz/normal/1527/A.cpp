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
    int n; cin >> n;
    int p = 1;
    while(p * 2 <= n) p *= 2;
    cout << p - 1 << "\n";
  }
}