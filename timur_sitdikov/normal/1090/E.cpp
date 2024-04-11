#include <bits/stdc++.h>

#define Pi acos(-1.)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define fi first
#define se second
#define FILE "474"
#define standart 1

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

const ll INF = 1e9 + 322;
const ll LINF = 2e18 + 474;
const ll MAXN = 2e5 + 500;
const double eps = 1e-12;

int n;
string horses[100];

int di[8] = {-1, -1, 1, 1, -2, -2, 2, 2};
int dj[8] = {-2, 2 , -2, 2, -1, 1, -1 , 1};

char grid[8][8], greed[8][8];
int prvi[8][8], prvj[8][8];
int used[8][8];

vector<pair<pii, pii> > moves;

queue<pii> q;

bool is_good(int i, int j) {
    return (0 <= i && i < 8 && 0 <= j && j < 8);
}


void bfs(int i0, int j0) {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            used[i][j] = 0;
            prvi[i][j] = prvj[i][j] = -1;
        }
    }
    while(!q.empty()) {
        q.pop();
    }
    q.push(mp(i0, j0));
    used[i0][j0] = 1;
    int target_i = -1, target_j = -1;
    while(!q.empty()) {
        int ii = q.front().fi;
        int jj = q.front().se;
        //cout << ii << " " << jj << " ii jj \n";
        q.pop();
        if(grid[ii][jj] != grid[i0][j0]) {
            target_i = ii;
            target_j = jj;
            break;
        }
        for(int k = 0; k < 8; k++) {
            int i1 = ii + di[k];
            int j1 = jj + dj[k];
            if(is_good(i1, j1) && !used[i1][j1] && mp(i1, j1) > mp(i0, j0)) {
                used[i1][j1] = 1;
                q.push(mp(i1, j1));
                prvi[i1][j1] = ii;
                prvj[i1][j1] = jj;
            }
        }
    }
    assert(target_i != -1);
    while(target_i != i0 || target_j != j0) {
        int new_target_i = prvi[target_i][target_j];
        int new_target_j = prvj[target_i][target_j];
        swap(grid[target_i][target_j], grid[new_target_i][new_target_j]);
        moves.pb(mp(mp(target_i, target_j), mp(new_target_i, new_target_j)));
        target_i = new_target_i;
        target_j = new_target_j;
    }
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> horses[i];
        grid[horses[i][1] - '1'][horses[i][0] - 'a'] = 1;
    }
    int n1 = n;
    if(n > 32) {
        n1 = 64 - n;
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 8; j++) {
                swap(grid[i][j], grid[7-i][7-j]);
            }
        }
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                grid[i][j] ^= 1;
            }
        }
    }
        int top = 0;
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                if(!grid[i][j] && top < n1) {
                    bfs(i, j);
                }
                top++;
            }
        }
        if(n > 32) {
            for(int i = 0; i < moves.size(); i++) {
                swap(moves[i].fi, moves[i].se);
                moves[i].fi.fi = 7 - moves[i].fi.fi;
                moves[i].fi.se = 7 - moves[i].fi.se;
                moves[i].se.fi = 7 - moves[i].se.fi;
                moves[i].se.se = 7 - moves[i].se.se;
            }
        }
        cout << moves.size() << '\n';
        for(int i = 0; i < moves.size(); i++) {
            cout << char(moves[i].fi.se + 'a') << char(moves[i].fi.fi + '1')
            <<'-'<< char(moves[i].se.se + 'a') << char(moves[i].se.fi + '1') << '\n';
        }
}



int main() {
    if(!standart) {
        freopen(FILE".in", "r", stdin);
        freopen(FILE".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    setlocale(LC_ALL, "Russian");
    int T = 1; //cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}