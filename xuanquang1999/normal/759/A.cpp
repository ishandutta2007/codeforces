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
#define maxN 200005
#define maxK 20
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

int n, p[maxN], b[maxN], verCnt, ccCnt, OneCnt;
bool visited[maxN];

void DFS(int u) {
    if (!visited[u]) {
        ++verCnt;
        visited[u] = true;
        DFS(p[u]);
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &p[i]);
    fto(i, 1, n) scanf("%d", &b[i]);

    int ans = n;
    fto(i, 1, n) {
        if (!visited[i]) {
            verCnt = 0;
            DFS(i);
            ans -= max(0, verCnt-1);
            ++ccCnt;
//            if (verCnt == 1) ++OneCnt;
        }
    }
//    debug(ccCnt);
//    debug(OneCnt);
    if (ccCnt == 1) ans = 0;
    int sum = accumulate(b+1, b+n+1, 0);
    ans += 1-sum%2;
    cout << ans;
//    if (OneCnt <= 1) cout << (ccCnt-1)*2 + (1-sum%2);
//    else if (OneCnt == ccCnt) cout << OneCnt + (1-sum%2);
//    else cout << (ccCnt-OneCnt)*2 + OneCnt - 1 + (1-sum%2);


    return 0;
}