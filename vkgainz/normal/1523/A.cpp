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
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<int> in;
    for(int i = 0; i < n; i++) {
      if(s[i] == '1') in.push_back(i);
    }
    vector<bool> alive(n);
    for(int i = 0; i < n; i++) {
      if(s[i] == '1') alive[i] = true;
    }
    for(int cyc = 0; cyc < min(m, n + 10); cyc++) {
      vector<bool> temp(n);
      for(int i = 0; i < n; i++) temp[i] = alive[i];
      for(int j = 0; j < n; j++) {
        int num = 0;
        if(j && alive[j - 1]) ++num;
        if(j < n - 1 && alive[j + 1]) ++num;
        if(num == 1 && !alive[j])
          temp[j] = true;
      }
      for(int i = 0; i < n; i++) alive[i] = temp[i];
    }
    string ret = "";
    for(int i = 0; i < n; i++) {
      if(alive[i]) ret += "1";
      else ret += "0";
    }
    cout << ret << "\n";
  }
}