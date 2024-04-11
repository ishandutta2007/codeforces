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
  int t; cin >> t;
  while(t--) {
    string s; cin >> s;
    int n = s.length();
    bool work = false;
    for(int j=0;j<8;j++) {
      int sum = 0;
      bool curr = true;
      for(int i=0;i<n;i++) {
        if(j&(1<<(s[i]-'A'))) {
          ++sum;
        }
        else {
          --sum;
        }
        if(sum < 0) curr = false;
      }
      if(sum != 0) curr = false;
      work = work || curr;
    }
    if(work) cout << "YES" << "\n";
    else cout << "NO" << "\n";
  }
}