#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
#define X first
#define Y second

ii operator + (ii a, ii b) {
    return ii(a.X + b.X, a.Y + b.Y);
}
const ii mv[8] = {ii(1, 2), ii(1, -2), ii(2, 1), ii(2, -1), ii(-1, 2), ii(-1, -2), ii(-2, 1), ii(-2, -1)};
int d[8][8];
ii tr[8][8];
int need[8][8], h[8][8];
bool inside(ii a) {
    return a.X >= 0 && a.X < 8 && a.Y >= 0 && a.Y < 8;
}
vector<pair<ii, ii>> ans;


void trace(ii st, ii en) {
    //cout << st.X << " " << st.Y << " " << en.X << " " << en.Y << '\n';
    if (st == en) return;
    ii ns = tr[st.X][st.Y];
    if (h[ns.X][ns.Y]) {
        trace(ns, en);
        ans.push_back(make_pair(st, ns));
    } else {
        ans.push_back(make_pair(st, ns));
        trace(ns, en);
    }

}
void BFS(int sx, int sy) {
    if (h[sx][sy]) return;
    queue<ii> q;
    memset(d, 0, sizeof(d));
    d[sx][sy] = 1;
    q.push(ii(sx, sy));
    while (!q.empty()) {
        ii cur = q.front(); q.pop();
        for(int i = 0; i < 8; i++) {
            ii ncur = cur + mv[i];
            if (inside(ncur) && !d[ncur.X][ncur.Y]) {
                d[ncur.X][ncur.Y] = d[cur.X][cur.Y] + 1;
                tr[ncur.X][ncur.Y] = cur;
                q.push(ncur);
            }
        }
    }

    int step = 10000;
    ii use;
    for(int nx = 0; nx < 8; nx++) 
        for(int ny = 0; ny < 8; ny++) 
            if (!need[nx][ny] && d[nx][ny] < step && h[nx][ny]) {
                step = d[nx][ny];
                use = ii(nx, ny);
            }
    assert(step != 10000);
    //cout << sx << " " << sy << '\n';
    //cout << "+"<< use.X << " " << use.Y << '\n';
    trace(use, ii(sx, sy));
    h[use.X][use.Y] = 0;
    h[sx][sy] = 1;
}

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        h[s[0] - 'a'][s[1] - '1'] = 1;
    }

    for(int i = 0; i < n; i++) need[i % 8][i / 8] = 1;
    
    for(int i = 0; i < n; i++) {
        int sx = i % 8, sy = i / 8;
        BFS(sx, sy);
    }
    assert(ans.size() <= 1500);
    cout << ans.size() << '\n';
    for(auto i : ans) 
        cout << char(i.X.X + 'a') << i.X.Y + 1 << "-" 
            << char(i.Y.X + 'a') << i.Y.Y + 1 << '\n'; 
}