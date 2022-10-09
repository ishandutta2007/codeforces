// 1186C
// stringhe binarie con numeri uguali in posizioni uguali pari
// idee: se il numero di 1 ha la stessa parit la stringa va bene

#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, n, res, check1;
string a, b;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> a >> b;
  res = 0;
  k = 0;
  for (i = 0; i < b.size(); i++) {
    if (a[i] == '1') {
      k++;
    }
    if (b[i] == '1') {
      k--;
    }
  }
  if (k % 2 == 0) {
    res++;
  }

  for (i = b.size(); i < a.size(); i++) {
    if (a[i] == '1') {
      k++;
    }
    if (a[i - b.size()] == '1') {
      k--;
    }
    if (k % 2 == 0) {
      res++;
    }
  }

  cout << res;

  return 0;
}