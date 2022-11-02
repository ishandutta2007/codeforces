#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int T, n;
string s;

int main(){
  cin >> T;
  for(int t=1; t<=T; t++){
    cin >> n >> s;
    int cnt = 0;
    for(int i=n-1; i>=0 && s[i] == '>'; i--)
      cnt++;
    int cnt2 = 0;
    for(int i=0; i<n && s[i] == '<'; i++)
      cnt2++;
    cout << min(cnt, cnt2) << endl;
  }

  return 0;
}