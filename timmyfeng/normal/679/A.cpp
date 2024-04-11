#include <bits/stdc++.h>
using namespace std;

const int P[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

bool query(int x) {
  cout << x << endl;
  string res;
  cin >> res;
  return res[0] == 'y';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> divisors;
  for (int i = 0; i < 4; ++i) {
    if (query(P[i])) {
      divisors.push_back(P[i]);
    }
  }

  if (divisors.empty()) {
    cout << "prime" << endl;
    exit(0);
  }
  
  if (divisors.size() > 1) {
    cout << "composite" << endl;
    exit(0);
  }

  if (query(divisors[0] * divisors[0])) {
    cout << "composite" << endl;
    exit(0);
  }

  for (int i = 4; i < 15; ++i) {
    if (query(P[i])) {
      cout << "composite" << endl;
      exit(0);
    }
  }

  cout << "prime" << endl;
}