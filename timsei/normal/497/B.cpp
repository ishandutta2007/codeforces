#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, A[N], tc, td, ans1[N], ans2[N], p1[N], p2[N];

vector <int> C[3];

vector < pair <int, int> > ans;

int main() {
  cin >> n;
  for(int i = 1; i <= n; ++ i) {
    scanf("%d", &A[i]);
    C[A[i]].push_back(i);
    p1[i] = (int)(C[1].size()) - 1;
    p2[i] = (int)(C[2].size()) - 1;
  }
  for(int i = 1; i <= n; ++ i) {
    //cerr << i <<" " << p1[i] <<" " << p2[i] << endl;
    if(p1[i] == -1 || A[i] != 1) ++ p1[i];
    if(p2[i] == -1 || A[i] != 2) ++ p2[i];
    //cerr << i <<" " << p1[i] << " " << p2[i] << endl;
  }
  for(int i = 1; i <= n; ++ i) {
    int a = 0, b = 0;
    int last;
    bool ok = 1;
    for(int j = 1; j <= n; j = last + 1) {
      int aa = p1[j], bb = p2[j];
      if(aa + i - 1 >= C[1].size()) aa = n + 1;
      else aa = C[1][aa + i - 1];
      if(bb + i - 1 >= C[2].size()) bb = n + 1;
      else bb = C[2][bb + i - 1];
      //cerr << i <<" " << j << " " << aa <<" " << bb << endl; 
      if(aa == bb && aa == n + 1) {
	ok = 0; break;
      }
      else {
	if(aa < bb) ++ a, last = aa;
	else ++ b, last = bb;
      }
    }
    if(!ok) continue;
    if(A[n] == 1) {
      if(a > b) {
	ans.push_back(make_pair(a, i));
      }
    }
    else {
      if(a < b) ans.push_back(make_pair(b, i));
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for(int i = 0; i < (int) ans.size(); ++ i) {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }
}