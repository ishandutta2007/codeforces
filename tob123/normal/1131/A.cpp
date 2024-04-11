#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll w1,  h1, w2, h2;

int main(){
  cin >> w1 >> h1 >> w2 >> h2;

  ll res = 2*(w1+2) + 2*(h1+h2);
  cout << res << endl;

  return 0;
}