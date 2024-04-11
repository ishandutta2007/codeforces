//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 2005
#define oo 3000000000000000000LL
#define sz(s) int(s.size())
#define all(s) s.begin(), s.end()

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

template <class T>
void read(vector<T> &v) {
    T x;
    cin >> x;
    v.pb(x);
}

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m, deg[maxN][maxN];
char s[maxN][maxN];
bool visited[maxN][maxN];

bool inBound(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 0, n-1) scanf("%s", s[i]);

    queue<ii> q;
    fto(x, 0, n-1) {
        fto(y, 0, m-1) {
            if (s[x][y] == '.') {
                fto(i, 0, 3) {
                    int u = x+dx[i], v = y+dy[i];
                    if (inBound(u, v) && s[u][v] == '.') ++deg[x][y];
                }
                if (deg[x][y] == 1) visited[x][y] = true, q.push(mp(x, y));
            }
        }
    }

    while (!q.empty()) {
        int x = q.front().ff, y = q.front().ss; q.pop();
//        fto(i, 0, n-1) {
//            fto(j, 0, m-1) printf("%d ", deg[i][j]);
//            puts("");
//        }
//        printf("%d %d\n", x, y);
//        fto(i, 0, n-1) printf("%s\n", s[i]);
        if (s[x][y] == '.') {
            fto(i, 0, 3) {
                int u = x+dx[i], v = y+dy[i];
                if (inBound(u, v) && s[u][v] == '.') {
                    if (i == 0) s[x][y] = 'v', s[u][v] = '^';
                    else if (i == 1) s[x][y] = '<', s[u][v] = '>';
                    else if (i == 2) s[x][y] = '^', s[u][v] = 'v';
                    else if (i == 3) s[x][y] = '>', s[u][v] = '<';

                    fto(j, 0, 3) {
                        int a = u+dx[j], b = v+dy[j];
                        if (inBound(a, b) && !visited[a][b] && s[a][b] == '.') {
                            --deg[a][b];
                            if (deg[a][b] == 1) visited[a][b] = true, q.push(mp(a, b));
                        }
                    }
                }
            }
            if (s[x][y] == '.') {
                puts("Not unique");
                return 0;
            }
        }
    }

    fto(x, 0, n-1) {
        fto(y, 0, m-1) {
            if (s[x][y] == '.') {
                puts("Not unique");
                return 0;
            }
        }
    }
    fto(x, 0, n-1) printf("%s\n", s[x]);



    return 0;
}