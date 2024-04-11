#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 998244353
#define MAXN 1000005
typedef int ll;
using namespace std;
ll i,j,k,z,q,timer,x,y,n,m, cnt, even, flag, x1,y1,x2,y2, boom,r,c;
string expected[305][305];
deque<char> cur[305][305];
int cursz[305][305];
vector<pii> shits[2], toshits[2];
int pnt[2];
vector<pair<pii, pii> > ans;
void Move(int x1, int y1, int x2, int y2, int p = -1) {
    shits[p].push_back(mp(x2, y2));
    char c = cur[x1][y1].back();
    cur[x1][y1].pop_back();
    cur[x2][y2].push_front(c);
    x1++;y1++;x2++;y2++;
    ans.push_back(mp(mp(x1, y1), mp(x2, y2)));
}

void move_inside(int x1, int y1, int x2, int y2) {
    if (x1 == x2 && y1 == y2)
        return;
    if (x1 == x2 || y1 == y2) {
        Move(x1, y1, x2, y2);
        return;
    }
    Move(x1, y1, x2, y1);
    Move(x2, y1, x2, y2);
}

void Prepare(int i, int j, int val) {
    if (val == 0) {
        if (i < n/2) {
            if (j > 0)
                toshits[0].push_back(mp(i,j-1));
            else
                toshits[0].push_back(mp(i,j+1));
        } else {
            toshits[0].push_back(mp(0,j));
        }
    } else {
        if (i >= n/2) {
            if (j > 0)
                toshits[1].push_back(mp(i,j-1));
            else
                toshits[1].push_back(mp(i,j+1));
        } else {
            toshits[1].push_back(mp(n-1,j));
        }
    }
}
void MoveTo(int i, int j, int val) {
    if (val == 0) {
        if (i < n/2) {
            if (j > 0)
                Move(i,j-1, i, j);
            else
                Move(i,j+1, i, j);
        } else {
            Move(0,j, i, j);
        }
    } else {
        if (i >= n/2) {
            if (j > 0)
                Move(i,j-1, i, j);
            else
                Move(i,j+1, i, j);
        } else {
            Move(n-1, j, i, j);
        }
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
        string s;
        cin >> s;
        for (int k = 0; k < s.size(); k++)
            cur[i][j].push_back(s[k]);
        cursz[i][j] = s.size();
    }

    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
        cin >> expected[i][j];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < cursz[i][j]; k++) {
                if (cur[i][j].back() == '0') {
                    if (i < n/2) {
                        if (j > 0)
                            Move(i, j, i, j-1, 0);
                        else
                            Move(i, j, i, j+1, 0);
                    } else {
                        Move(i, j, 0, j, 0);
                    }
                }
                else {
                    if (i >= n/2) {
                        if (j > 0)
                            Move(i, j, i, j-1, 1);
                        else
                            Move(i, j, i, j+1, 1);
                    } else {
                        Move(i, j, n-1, j, 1);
                    }
                }
            }
        }

    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
        int sz = expected[i][j].size();
        for (int k = sz-1; k >= 0; k--) {
            Prepare(i, j, (int)(expected[i][j][k]-'0'));
        }
    }

    for (int p = 0; p < 2; p++)
    for (int j = 0; j < shits[p].size(); j++) {
        move_inside(shits[p][j].X, shits[p][j].Y, toshits[p][j].X, toshits[p][j].Y);
    }

    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
        int sz = expected[i][j].size();
        for (int k = sz-1; k >= 0; k--) {
            MoveTo(i, j, (int)(expected[i][j][k]-'0'));
        }
    }

    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < cur[i][j].size(); k++)
                cout << cur[i][j][k];
            cout << " ";
        }
        cout << endl;
    }*/
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        printf("%d %d %d %d\n", ans[i].X.X, ans[i].X.Y, ans[i].Y.X, ans[i].Y.Y);
    }
    return 0;
}