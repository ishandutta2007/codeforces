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
#define maxN 35
#define maxX 305
#define oo 1000000007

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

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int n, t[maxN], a[maxX][maxX];
bool visited[maxX][maxX][8][maxN];

void DFS(int x, int y, int dir, int i) {
    if (i > n) return;
    if (visited[x][y][dir][i]) return;
    visited[x][y][dir][i] = true;

    fto(k, 0, t[i]-1) a[x+dx[dir]*k][y+dy[dir]*k] = true;
    DFS(x + dx[dir]*(t[i]-1) + dx[(dir+7)%8], y + dy[dir]*(t[i]-1) + dy[(dir+7)%8], (dir+7)%8, i+1);
    DFS(x + dx[dir]*(t[i]-1) + dx[(dir+1)%8], y + dy[dir]*(t[i]-1) + dy[(dir+1)%8], (dir+1)%8, i+1);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &t[i]);

    DFS(150, 150, 0, 1);

    int ans = 0;
    fto(i, 0, maxX-1) {
        fto(j, 0, maxX-1) ans += a[i][j];
    }

    printf("%d", ans);

    return 0;
}