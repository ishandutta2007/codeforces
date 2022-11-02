#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
  int n, d;
  map<string, int> id;
  vector<string> names;
  vector<int> A, B, t;

  ios::sync_with_stdio(false);

  cin >> n >> d;
  t.resize(n);
  for(int i=0; i<n; ++i) {
    string a, b;

    cin >> a >> b >> t[i];
    if(id.count(a) == 0) {
      int new_id = id.size();
      id[a] = new_id;
      names.push_back(a);
    }
    if(id.count(b) == 0) {
      int new_id = id.size();
      id[b] = new_id;
      names.push_back(b);
    }
    A.push_back(id[a]);
    B.push_back(id[b]);
  }

  vector<pair<int, int> > friends;
  for(int i=0; i<n; ++i)
    for(int j=i+1; j<n; ++j)
      if(A[i] != B[i] && A[i] == B[j] && B[i] == A[j] && t[j] - t[i] > 0 && t[j] - t[i] <= d)
	friends.push_back(make_pair(min(A[i], B[i]), max(A[i], B[i])));

  sort(friends.begin(), friends.end());
  friends.erase(unique(friends.begin(), friends.end()), friends.end());

  cout << friends.size() << "\n";
  for(int i=0; i<(int)friends.size(); ++i)
    cout << names[friends[i].first] << " " << names[friends[i].second] << "\n";

  return 0;
}