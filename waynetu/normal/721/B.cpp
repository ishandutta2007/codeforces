#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector< vector< string > > v(101);
long long int n, k, t, c;
string passwd, s;
long long int best, worst;

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    v[s.length()].push_back(s);
  }
  cin >> passwd;
  t = 0;
  c = 0;
  for (long long int i = 1; i < passwd.length(); ++i) {
    t += v[i].size();
  }
  best = t + 1 + 5 * ((t) / k);
  t += v[passwd.length()].size();
  worst = t + 5 * ((t - 1)/ k);
  cout << best << ' ' << worst << endl;
  return 0;
}