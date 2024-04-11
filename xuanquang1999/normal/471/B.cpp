//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define fordit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 2005

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, cnt;
vector<int> id, pos[maxN], ans[3], b;

void Try(int x) {
    if (cnt == 3) {
        puts("YES");
        fto(i, 0, 2) {
            forit(it, ans[i]) printf("%d ", *it);
            puts("");
        }
        exit(0);
    }
    if (x == id.size()) {
        ans[cnt++].assign(b.begin(), b.end());
        return;
    }
    do {
        forit(it, pos[id[x]]) b.push_back(*it);
        Try(x+1);
        fto(i, 0, pos[id[x]].size()-1) b.pop_back();
    } while (next_permutation(pos[id[x]].begin(), pos[id[x]].end()));
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) {
        int x;
        scanf("%d", &x);
        if (pos[x].size() == 0) id.pb(x);
        pos[x].pb(i);
    }
    sort(id.begin(), id.end());
    forit(it, id) {
        sort(pos[*it].begin(), pos[*it].end());
    }
    Try(0);

    puts("NO");

    return 0;
}