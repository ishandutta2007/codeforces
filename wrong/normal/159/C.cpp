#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

string input()
{
  int k;
  string s;
  cin >> k >> s;

  stringstream ss;
  for(int i=0; i<k; ++i)
    ss << s;
  return ss.str();
}

struct BIT {
  int N;
  vector<int> b;
  BIT(int n) : N(n), b(n+1, 0) { }
  void add(int x, int v) {
    for(; x<=N; x+=(x&-x))
      b[x] += v;
  }
  int sum(int x) {
    int s = 0;
    for(; x>0; x-=(x&-x))
      s += b[x];
    return s;
  }
};

void del(string& t, const vector<int>& o, const vector<int>& q)
{
  BIT b(o.size());
  for(int i=0; i<(int)q.size(); ++i) {
    int lo = -1, hi = o.size()-1;
    while(hi-lo > 1) {
      int mid = (hi+lo) / 2;
      if(mid+1 - b.sum(mid+1) >= q[i])
	hi = mid;
      else
	lo = mid;
    }
    t[o[hi]] = '_';
    b.add(hi+1, 1);
  }
}

int main()
{
  ios::sync_with_stdio(false);

  string t = input();
  int n;
  cin >> n;

  vector<int> occur[26], query[26];
  for(int i=0; i<(int)t.size(); ++i)
    occur[t[i]-'a'].push_back(i);
  for(int i=0; i<n; ++i) {
    int p;
    string c;
    cin >> p >> c;
    query[c[0]-'a'].push_back(p);
  }

  for(int i=0; i<26; ++i)
    del(t, occur[i], query[i]);
  t.erase(remove(t.begin(), t.end(), '_'), t.end());

  cout << t << "\n";
  return 0;
}