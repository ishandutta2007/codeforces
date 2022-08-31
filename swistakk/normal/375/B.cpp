#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <utility>
#define MP make_pair
#define PB push_back

typedef long long ll;

using namespace std;

const int N = 5005;
int mat[N][N];
int rows[N];
vector<int> start[N];
int end[N];
int licz[N][N];
char heh[N];
int main()
{
  // nie zapomnij o ll
  //ios_base::sync_with_stdio(0);
  int n, m;
  scanf("%d%d", &n, &m);
  
  //cin>>n>>m;
  for (int i = 1; i <= n; i++) {
    scanf("%s", heh + 1);
    /* char d;
    cin>>d;
    cin.putback(d); */
    for (int j = 1; j <= m; j++) {
      char c = heh[j];
      //cin>>c;
      mat[i][j] = int(c) - int('0');
      //cout<<c;
    }
    //cout<<endl;
  }
  for (int i = 1; i <= n; i++) {
    int dl = 0;
    for (int j = 1; j <= m + 1; j++) {
      if (mat[i][j] == 0 && mat[i][j - 1] == 1) {
        for (int k = j - 1; mat[i][k] == 1; k--) {
          licz[k][j - 1]++;
        }
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = m; j >= i; j--) {
      licz[i][j] += licz[i][j + 1];
    }
  }
  int res = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = i; j <= m; j++) {
      res = max(res, (j - i + 1) * licz[i][j]);
    }
  }
  printf("%d\n", res);
  //cout<<res<<endl;
  /* 
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < start[i].size(); j++) {
      int kon = start[i][j];
      end[kon] */
  /* sort(rows + 1, rows + 1 + n);
  int res = 0;
  for (int i = n; i >= 1; i--) {
    res = max(res, rows[i] * (n - i + 1));
  }
  cout<<res<<endl; */
  
  
  
  // nie zapomnij o ll
  return 0;
}