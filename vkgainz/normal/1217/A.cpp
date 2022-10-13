#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first
const int MX = 1e5+5;

int main() {
  int T; cin >> T;
  while(T--) {
    int str, in, exp; cin >> str >> in >> exp;
    int a = max(0, (int)ceil((in-str+exp+1)*1.0/2));
    if(a<=exp) {
      cout << exp-a+1 << "\n";
    }
    else {
      cout << 0 << "\n";
    }
  }
}