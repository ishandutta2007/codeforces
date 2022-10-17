#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) //ignore
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

const int LARGE = 1e9+10;

bool smin(auto &a, auto&& b) { return (b < a) ? (a = b, 1) : 0; } 
bool smax(auto &a, auto&& b) { return (a < b) ? (a = b, 1) : 0; } 

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;

  // precompute dists
  vector<vi> dist_to_tower(1<<n, vi(n,LARGE));
  vector<vi> dist_to_task(1<<n, vi(m,LARGE));
  vector<vi> dist_from_task_to_task(m, vi(m,LARGE));
  vector<vi> dist_from_task_to_tower(m, vi(n,LARGE));
  vi endtime(m);

  {
    vector<pii> tower(n);
    vector<pair<int,pii>> task(m);
    rep(i,0,n) cin>>tower[i].first>>tower[i].second;
    rep(i,0,m) {
      cin>>task[i].second.first>>task[i].second.second>>task[i].first;
      endtime[i] = task[i].first;
    }
    sort(all(endtime));
    sort(all(task));

    auto D = [&](pii p, pii q) {
      return abs(p.first-q.first) + abs(p.second-q.second);
    };

    rep(i,0,m) {
      rep(j,0,m) dist_from_task_to_task[i][j] = D(task[i].second, task[j].second);
      rep(j,0,n) dist_from_task_to_tower[i][j] = D(task[i].second, tower[j]);
    }

    rep(msk,0,(1<<n)) {
      rep(b,0,n) if(msk>>b&1) {
        rep(j,0,n) smin(dist_to_tower[msk][j], D(tower[b], tower[j]));
        rep(j,0,m) smin(dist_to_task[msk][j],  D(tower[b], task[j].second));
      }
    }
  }

  // earliest[msk][score] time we may reach score having visited msk towers
  vector<vi> earliest(1<<n, vi(m+1, LARGE));
  earliest[0][0] = -LARGE;

  // best[msk][task] best score ending at task having visited msk towers
  vector<vi> best(1<<n, vi(m, -1e9));

  int ans = 0;

  rep(msk,0,1<<n) {
    const auto& dist_tower = dist_to_tower[msk];
    const auto& dist_task = dist_to_task[msk];

    //debug(msk); debug(dist_tower); debug(dist_task);

    rep(score,0,m+1) {

      rep(tower,0,n) { // tower -> tower
        smin(earliest[msk|(1<<tower)][score],
            max(0, earliest[msk][score] + dist_tower[tower]));
      }

      rep(task,0,m) { // tower -> task
        if(max(0, earliest[msk][score] + dist_task[task]) <= endtime[task]) {
          smax(best[msk][task], score+1);
        }
      }

      rep(task0,0,m) if(best[msk][task0] == score) {
        smax(ans, score);

        rep(tower,0,n) { // task -> tower
          int d = min(dist_tower[tower], dist_from_task_to_tower[task0][tower]);
          smin(earliest[msk|(1<<tower)][score], endtime[task0] + d);
        }

        rep(task,task0+1,m) { // task -> task
          int d = min(dist_task[task], dist_from_task_to_task[task0][task]);
          if(endtime[task0] + d <= endtime[task]) {
            smax(best[msk][task], best[msk][task0]+1);
          }
        }
      }

    }
  }

  debug()
  debug(best);
  debug(earliest);

  cout << ans << endl;
}