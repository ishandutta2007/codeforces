#include <bits/stdc++.h>
using namespace std;

const int N = 1111111;

char s[N];
int n, s8;

int main() {
  cin >> n;
  scanf("%s", s + 1);
  for(int i = 1; i <= n; ++ i) if(s[i] == '8') ++ s8;
  cout << min(n / 11, s8) << endl;
}