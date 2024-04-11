#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }

int field[111][2];
int F[111][2];

map<vector<pair<int, int> >, int> memo;

int grundy(const vector<pair<int, int> >& fld)
{
    if (fld.empty()) {
        return 0;
    }
    if (memo.find(fld) != memo.end()) {
        return memo[fld];
    }

    int cr = 0;
    for (int i = 0; i < fld.size(); ++i) {
        chmax(cr, fld[i].first);
    }
    ++cr;

    set<int> gs;
    for (int i = 0; i < fld.size(); ++i) {
        for (int r = 0; r <= cr + 1; ++r) {
            F[r][0] = F[r][1] = -1;
        }
        for (int j = 0; j < fld.size(); ++j) {
            F[1 + fld[j].first][fld[j].second] = 0;
        }

        F[1 + fld[i].first][fld[i].second] = -1;
        for (int d = -1; d <= 1; ++d) {
            F[1 + d + fld[i].first][1 - fld[i].second] = -1;
        }

        vector<vector<pair<int, int> > > cs;
        for (int r = 1; r <= cr; ++r) {
            for (int c = 0; c < 2; ++c) {
                if (F[r][c] == 0) {
                    vector<pair<int, int> > w;
                    int br = r;
                    queue<int> qr, qc;
                    qr.push(r); qc.push(c);
                    w.push_back(make_pair(r - br, c));
                    F[r][c] = -1;
                    while (!qr.empty()) {
                        int rr = qr.front(), cc = qc.front();
                        qr.pop(); qc.pop();
                        if (F[rr + 1][cc] == 0) {
                            w.push_back(make_pair(rr + 1 - br, cc));
                            qr.push(rr + 1); qc.push(cc);
                            F[rr + 1][cc] = -1;
                        }
                        if (F[rr][1 - cc] == 0) {
                            w.push_back(make_pair(rr - br, 1 - cc));
                            qr.push(rr); qc.push(1 - cc);
                            F[rr][1 - cc] = -1;
                        }
                        if (F[rr + 1][1 - cc] == 0) {
                            w.push_back(make_pair(rr + 1 - br, 1 - cc));
                            qr.push(rr + 1); qc.push(1 - cc);
                            F[rr + 1][1 - cc] = -1;
                        }
                    }
                    sort(w.begin(), w.end());
                    cs.push_back(w);
                }
            }
        }

        int g = 0;
        for (int k = 0; k < cs.size(); ++k) {
            g ^= grundy(cs[k]);
        }
        gs.insert(g);
    }

    for (int i = 0; ; ++i) {
        if (gs.find(i) == gs.end()) {
            return memo[fld] = i;
        }
    }
}

int main()
{
    int R, N;
    cin >> R >> N;

    for (int i = 0; i < N; ++i) {
        int r, c;
        cin >> r >> c;
        --c;
        field[r][c] = -1;
        for (int d = -1; d <= 1; ++d) {
            field[r + d][1 - c]++;
        }
    }

    int br = -1;
    vector<pair<int, int> > fi;
    for (int i = 1; i <= R; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (field[i][j] == 0) {
                if (br < 0) br = i;
                fi.push_back(make_pair(i - br, j));
            }
        }
    }
    sort(fi.begin(), fi.end());

    cout << (grundy(fi) == 0 ? "LOSE" : "WIN") << endl;

    return 0;
}