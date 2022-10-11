#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

string g[1005];
int r, c;
// in row x, rowPS[x][y] counts how many of the first y characters are turned on
// note, x is zero-indexed
int rowPS[1005][1005];
// on col x, colPS[x][y] counts how many of the first y characters are turned on
// note, x is zero-indexed
int colPS[1005][1005];

int sizes[1005][1005];

int starSize(int x, int y) {
  if(g[x][y] != '*') return 0;
  int lhs = 0;
  int rhs = 1000;
  while(lhs != rhs) {
    int mid = (lhs+rhs+1)/2;
    if(x-mid < 0 || y-mid < 0 || x+mid+1 > r || y+mid+1 > c) {
      rhs = mid-1;
      continue;
    }
    if(rowPS[x][y+mid+1] - rowPS[x][y-mid] != 2*mid+1) {
      rhs = mid-1;
      continue;
    }
    if(colPS[y][x+mid+1] - colPS[y][x-mid] != 2*mid+1) {
      rhs = mid-1;
      continue;
    }
    lhs = mid;
  }
  return lhs;
}

void solve() {
  cin >> r >> c;
  for(int i = 0; i < r; i++) {
    cin >> g[i];
  }
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      rowPS[i][j+1] = rowPS[i][j] + (g[i][j] == '*' ? 1 : 0);
    }
  }
  for(int j = 0; j < c; j++) {
    for(int i = 0; i < r; i++) {
      colPS[j][i+1] = colPS[j][i] + (g[i][j] == '*' ? 1 : 0);
    }
  }
  int numStars = 0;
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      sizes[i][j] = starSize(i, j);
      if(sizes[i][j]) numStars++;
    }
  }
  memset(rowPS, 0, sizeof(rowPS));
  memset(colPS, 0, sizeof(colPS));
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      if(sizes[i][j] == 0) continue;
      rowPS[i][j-sizes[i][j]]++;
      rowPS[i][j+sizes[i][j]+1]--;
      colPS[j][i-sizes[i][j]]++;
      colPS[j][i+sizes[i][j]+1]--;
    }
  }
  for(int i = 0; i < 1000; i++) {
    for(int j = 0; j < 1000; j++) {
      rowPS[i][j+1] += rowPS[i][j];
      colPS[i][j+1] += colPS[i][j];
    }
  }
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      if(g[i][j] == '*') {
        if(rowPS[i][j] == 0 && colPS[j][i] == 0) {
          cout << "-1\n";
          return;
        }
      }
    }
  }
  cout << numStars << endl;
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      if(sizes[i][j]) {
        cout << (i+1) << " " << (j+1) << " " << sizes[i][j] << endl;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
  solve();
}