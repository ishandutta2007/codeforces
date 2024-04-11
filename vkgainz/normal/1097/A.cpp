#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first
const int MX = 1e5+5;

int main() {
  string s;
  string t[5];
  cin >> s;
  for(int i=0;i<5;i++) cin >> t[i];
  for(int i=0;i<5;i++) {
    if(t[i][0] == s[0] || t[i][1] == s[1]) {
      cout << "YES" << "\n";
      return 0;
    }
  }
  cout << "NO" << "\n";
}