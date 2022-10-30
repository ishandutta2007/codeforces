#include<iostream>
#include<vector>

using namespace std;

typedef long long Int;

int main()
{
  Int s, k;

  while(cin >> s >> k) {
    vector<Int> sol;

    if(k >= 32) {
      for(int i=0; i<=32; ++i) {
        if(s & (1LL<<i)) {
          sol.push_back(1LL << i);
        }
      }
    } else {
      vector<Int> F(k, 0);
      F[k-1] = 1;

      while(F.back() < s) {
        Int f = 0;
        for(int i=1; i<=k; ++i) {
          f += F[(int)F.size()-i];
        }
        F.push_back(f);
      }

      for(int i=(int)F.size()-1; i>=0; --i) {
        if(F[i] == 0) break;

        if(s >= F[i]) {
          s -= F[i];
          sol.push_back(F[i]);
        }
      }
    }

    if(sol.size() == 1) {
      sol.push_back(0);
    }

    cout << sol.size() << endl;
    for(int i=0; i<(int)sol.size(); ++i) {
      cout << sol[i];
      if(i+1 == (int)sol.size()) {
        cout << endl;
      } else {
        cout << ' ';
      }
    }
  }

  return 0;
}