#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define EACH(x, y) for(auto &x: y)
#define pll pair<ll, ll>
#define max(a,b) (a<b?b:a)
int main() {
  int N;
  cin >> N;
  while(N--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int pos=-1;
    for(int i =0; i < n; i++) {

      if(s[i] != ')') pos=i;
    }
    // base case
    if(pos == -1) {
      cout << "Yes\n";
      continue;
    }
    // 
    if(n-pos-1 > n/2) {
      cout << "Yes\n";
      continue;
    }
    cout << "No\n";
  }
}