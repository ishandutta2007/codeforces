#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first
const int MX = 1e5+5;

int main() {
  int t; cin >> t;
  while(t--) {
    int px, py; cin >> px >> py;
    string s; cin >> s;
    vector<int> in(4);
    fill(in.begin(), in.end(), 0);
    for(int i=0;i<s.length();i++) {
      if(s[i]=='R') ++in[0];
      if(s[i]=='U') ++in[1];
      if(s[i]=='L') ++in[2];
      if(s[i]=='D') ++in[3];
    }
    if(in[0] >= px && -in[2] <= px && in[1] >= py && -in[3] <= py) {
      cout << "YES" << "\n";
    }
    else cout << "NO" << "\n";
  }
}