#include<iostream>
#include<vector>
#include<cstring>
#include<cctype>
#include<queue>

using namespace std;

int R, C, K;

static int dx[] = {1, 0, -1, 0};
static int dy[] = {0, 1, 0, -1};

int encode(vector<int> px, vector<int> py)
{
  int c = 0;

  for(int i=0; i<K-1; ++i) {
    int dir;
    
    for(dir=0; dir<4; ++dir) {
      if(px[i]+dx[dir] == px[i+1] && py[i]+dy[dir] == py[i+1]) {
        break;
      }
    }

    c |= dir << (2*i);
  }

  return c;
}

void decode(int c, int x, int y, vector<int>& px, vector<int>& py)
{
  px.resize(K);
  py.resize(K);

  px[0] = x;
  py[0] = y;

  for(int i=0; i<K-1; ++i) {
    int d = (c >> (2*i)) & 3;

    px[i+1] = px[i] + dx[d];
    py[i+1] = py[i] + dy[d];
  }
}

char fld[15][16];
int dp[15][15][1<<16];

int main()
{
  while(cin >> R >> C) {
    memset(dp, ~0, sizeof(dp));

    vector<int> sx, sy;
    int gx, gy;
    K = 0;
    for(int i=0; i<R; ++i) {
      cin >> fld[i];

      for(int j=0; j<C; ++j) {
        if(isdigit(fld[i][j])) {
          int s = fld[i][j] - '1';
          
          if(s+1 > K) {
            K = s+1;
            sx.resize(K);
            sy.resize(K);
          }
          sx[s] = i;
          sy[s] = j;

          fld[i][j] = '.';
        } else if(fld[i][j] == '@') {
          gx = i;
          gy = j;
          
          fld[i][j] = '.';
        }
      }
    }

    queue<int> qx, qy, qs;
    qx.push(sx[0]);
    qy.push(sy[0]);
    qs.push(encode(sx, sy));
    dp[sx[0]][sy[0]][encode(sx, sy)] = 0;

    int cleared = 0;
    
    while(!qx.empty()) {
      int hx = qx.front(); qx.pop();
      int hy = qy.front(); qy.pop();
      int hs = qs.front(); qs.pop();

      if(hx == gx && hy == gy) {
        cout << dp[hx][hy][hs] << endl;
        cleared = 1;
        break;
      }

      vector<int> cx, cy;
      decode(hs, hx, hy, cx, cy);
      
      for(int i=0; i<4; ++i) {
        int hxx = hx+dx[i], hyy = hy+dy[i];

        if(hxx < 0 || hyy < 0) continue;
        if(hxx >= R || hyy >= C) continue;
        if(fld[hxx][hyy] == '#') continue;

        int die = 0;
        for(int j=1; j<K-1; ++j) {
          if(hxx == cx[j] && hyy == cy[j]) {
            die = 1;
            break;
          }
        }
        if(die) continue;

        vector<int> cxx(K), cyy(K);
        cxx[0] = hxx; cyy[0] = hyy;
        for(int i=1; i<K; ++i) {
          cxx[i] = cx[i-1];
          cyy[i] = cy[i-1];
        }

        int hss = encode(cxx, cyy);

        if(!~dp[hxx][hyy][hss] || dp[hxx][hyy][hss] > dp[hx][hy][hs] + 1) {
          dp[hxx][hyy][hss] = dp[hx][hy][hs] + 1;
          qx.push(hxx);
          qy.push(hyy);
          qs.push(hss);
        }
      }
    }

    if(!cleared) {
      cout << "-1" << endl;
    }
  }

  return 0;
}