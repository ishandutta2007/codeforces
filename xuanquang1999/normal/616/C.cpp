#include <bits/stdc++.h>
using namespace std;
#define debug(a) cout << #a << ": " << a << endl
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define maxN 1005
#define oo 1000000007

int m, n, cnt[maxN][maxN], CC[maxN][maxN], CCcnt;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
char s[maxN][maxN];
vector<ii> ans;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &m, &n);
    fto(i, 0, m-1) scanf("%s", s[i]);

    fto(i, 0, m-1) {
        fto(j, 0, n-1) {
            if (s[i][j] == '.' && cnt[i][j] == 0) {
                ++CCcnt;
                queue<ii> q;
                q.push(mp(i, j));
                cnt[i][j] = 1;
                ans.clear();
                while (!q.empty()) {
                    int x = q.front().ff, y = q.front().ss; q.pop();
                    ans.pb(mp(x, y));
                    fto(k, 0, 3) {
                        int u = x+dx[k], v = y+dy[k];
                        if (u < 0 || u >= m || v < 0 || v >= n) continue;
                        if (cnt[u][v] == 0 && s[u][v] == '.') {
                            cnt[u][v] = 1;
                            q.push(mp(u, v));
                        }
                    }
                }
                forit(it, ans) {
                    int x = it->ff, y = it->ss;
                    cnt[x][y] = ans.size();
                    CC[x][y] = CCcnt;
                }
            }
        }
    }

//    fto(i, 0, m-1) {
//        fto(j, 0, n-1) printf("%d ", cnt[i][j]);
//        printf("\n");
//    }

    fto(i, 0, m-1) {
        fto(j, 0, n-1) {
            if (s[i][j] == '*') {
                set<int> ss;
                int sum = 1;

                if (i > 0 && ss.find(CC[i-1][j]) == ss.end()) {
                    sum += cnt[i-1][j];
                    ss.insert(CC[i-1][j]);
                }
                if (i < m-1 && ss.find(CC[i+1][j]) == ss.end()) {
                    sum += cnt[i+1][j];
                    ss.insert(CC[i+1][j]);
                }
                if (j > 0 && ss.find(CC[i][j-1]) == ss.end()) {
                    sum += cnt[i][j-1];
                    ss.insert(CC[i][j-1]);
                }
                if (j < n-1 && ss.find(CC[i][j+1]) == ss.end()) {
                    sum += cnt[i][j+1];
                    ss.insert(CC[i][j+1]);
                }
                s[i][j] = '0' + sum%10;
            }
        }
    }

    fto(i, 0, m-1) printf("%s\n", s[i]);

    return 0;
}