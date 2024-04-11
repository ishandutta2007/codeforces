#include <bits/stdc++.h>

using namespace std;


typedef pair<int, int> ii;
#define X first
#define Y second

const int D = 5e2 + 10;
const int N = 5e3 + 10;

int h[D][N];
ii t[D][N];
int use[D][N];
int d, n;
void solve(){
    queue<ii> q;
    h[0][0] = 1;
    q.push(ii(0,0));
    while (!q.empty()){
        ii cur = q.front(); q.pop();
        for(int i = 0; i < 10; i++){
            ii ncur = ii((cur.first * 10 + i) % d, cur.second + i);
            if (ncur.second > n) continue;
            if (h[ncur.X][ncur.Y]) continue;
            h[ncur.X][ncur.Y] = h[cur.X][cur.Y] + 1;
            t[ncur.X][ncur.Y] = cur;
            use[ncur.X][ncur.Y] = i;
            q.push(ncur);
        }
    }
    if (!h[0][n]){
        cout << "-1";
        return;
    }
    string s;
    ii cur = ii(0, n);
    for(int i = 1; i < h[0][n]; i++){
        s.push_back('0' + use[cur.X][cur.Y]);
        cur = t[cur.X][cur.Y];
    }
    reverse(s.begin(), s.end());
    cout << s;
}
int main() {
    cin >> d >> n;
    solve();
}