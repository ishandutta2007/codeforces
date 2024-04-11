#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

map<string, int> buy;

int main()
{
  int n, m, v[100];
  cin >> n >> m;
  for(int i=0; i<n; ++i) cin >> v[i];
  for(int i=0; i<m; ++i) {
    string s;
    cin >> s;
    buy[s]++;
  }
  vector<int> ct;
  for(map<string, int>::iterator it=buy.begin(); it!=buy.end(); ++it) {
    ct.push_back(it->second);
  }
  sort(ct.begin(), ct.end());
  reverse(ct.begin(), ct.end());
  int minimum = 0, maximum = 0;
  sort(v, v+n);
  for(int i=0; i<ct.size(); ++i) {
    minimum += ct[i] * v[i];
    maximum += ct[i] * v[n-i-1];
  }
  cout << minimum << " " << maximum << endl;
  return 0;
}