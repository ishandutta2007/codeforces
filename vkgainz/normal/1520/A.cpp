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
    vector<int> f(26), l(26);
    vector<int> num(26);
    for(int i=0;i<s.length();i++) {
      l[s[i]-'A'] = i;
      ++num[s[i]-'A'];
    }
    for(int i=s.length()-1;i>=0;i--){
      f[s[i]-'A'] = i;
    }
    bool work = true;
    for(int i=0;i<26;i++) {
      if((num[i] > 0) && num[i] != (l[i] - f[i] + 1)) {
        work = false;
      }
    }
    if(!work) cout << "NO" << "\n";
    else cout << "YES" << "\n";
  }
}