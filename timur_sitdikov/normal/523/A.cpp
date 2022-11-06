#include <iostream>
#include <string>

using namespace std;

const int amt = 4;
int di[amt] = {0, 0, 1, 1};
int dj[amt] = {0, 1, 0, 1};

int main () {
 int n, m;
 cin >> m >> n;
 const int maxn = 234;
 char answer[maxn][maxn]; 
 string s;
 for (int i = 0; i < n; ++i) {
  cin >> ws >> s;
  for (int j = 0; j < m; ++j) {
   for (int t = 0; t < amt; ++t) {
    answer[j + j + di[t]][i + i + dj[t]] = s[j];
   }
  }
 }  
 for (int i = 0; i < m + m; ++i) {
  for (int j = 0; j < n + n; ++j ){
   cout << answer[i][j];
  }
  cout << "\n";
 }
 return 0;
}