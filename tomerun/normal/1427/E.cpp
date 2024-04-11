#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

int64_t X;

int main() {
  cin >> X;
  vector<string> ans;
  while (X != 1) {
    int len = 0;
    int64_t t = X;
    while (t > 0) {
      len += 1;
      t >>= 1;
    }
    int64_t b = X;
    for (int i = 0; i < len - 1; ++i) {
      ostringstream stm;
      stm << b << " + " << b;
      ans.push_back(stm.str());
      b <<= 1;
    }
    int64_t c = X + b;
    {
      ostringstream stm;
      stm << X << " + " << b;
      ans.push_back(stm.str());
    }
    int64_t d = X ^ b;
    {
      ostringstream stm;
      stm << X << " ^ " << b;
      ans.push_back(stm.str());
    }
    int64_t e = X + d;
    {
      ostringstream stm;
      stm << X << " + " << d;
      ans.push_back(stm.str());
    }
    if ((X >> (len - 2)) == 3) {
      int64_t f = c ^ e;
      {
        ostringstream stm;
        stm << c << " ^ " << e;
        ans.push_back(stm.str());
      }
      X = f;
    } else {
      int64_t f = b ^ e;
      {
        ostringstream stm;
        stm << b << " ^ " << e;
        ans.push_back(stm.str());
      }
      while ((X ^ f) >= X) {
        ostringstream stm;
        stm << f << " + " << f;
        ans.push_back(stm.str());
        f <<= 1;
      }
      {
        ostringstream stm;
        stm << X << " ^ " << f;
        ans.push_back(stm.str());
      }
      X ^= f;
    }
  }
  cout << ans.size() << endl;
  for (string& s : ans) {
    cout << s << endl;
  }
}