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
    string s; cin >> s;
    int x = 0;
    for(int i=0;i<n;i++) 
      x+=(s[i] - '0');
    if(s[0] == '0' || s[n-1] == '0' || x%2 == 1) {
      cout << "NO" << "\n";
      continue;
    }
    x /= 2;
    bool lst = true;
    string a, b;
    for(int i=0;i<n;i++) {
      if(s[i] == '0') {
        if(lst) a+="(", b+=")";
        else a+=")", b+="(";
        lst = !lst;
      }
      else {
        if(x) {
          a+="(", b+="("; 
          --x;
        }
        else a+=")", b+=")";
      }
    }
    cout << "YES" << "\n";
    cout << a << "\n";
    cout << b << "\n";
  }
}