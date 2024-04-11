#include<iostream>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

int n, m;
string name[1024];
int score[1024];

int main()
{
  map<string, int> nn;
  ios::sync_with_stdio(false);
  cin >> n;
  m = 0;
  for(int i=0; i<n; ++i) {
    string k;
    int p;
    cin >> k >> p;
    if(nn.find(k) == nn.end())
      nn[k] = m++;
    name[nn[k]] = k;
    score[nn[k]] = max(score[nn[k]], p);
  }
  cout << m << "\n";
  for(int i=0; i<m; ++i) {
    int a = 0, b = 0;
    for(int j=0; j<m; ++j) {
      if(score[i] < score[j]) b++;
      if(score[i] >= score[j]) a++;
    }
    cout << name[i] << " ";
    if(100 * a >= 99 * m) cout << "pro\n";
    else if(10 * a >= 9 * m) cout << "hardcore\n";
    else if(5 * a >= 4 * m) cout << "average\n";
    else if(2 * a >= m) cout << "random\n";
    else cout << "noob\n";
  }
  return 0;
}