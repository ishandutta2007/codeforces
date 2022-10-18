//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define ftos(i, l, r, a) for(int i = (l); i <= (r); i += a)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define fordit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 1000005

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, m;
vector<int> v[maxN];
vector<int> d[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, n) {
        int x;
        scanf("%d", &x);
        if (x <= 1000000) v[x].pb(i);
    }

    fto(i, 1, m) {
        ftos(j, i, m, i) d[j].pb(i);
    }

    int ans = 0, lcm = 0;
    fto(i, 1, m) {
        int sum = 0;
        forit(it, d[i]) sum += v[*it].size();
        if (sum > ans) {
            lcm = i;
            ans = sum;
        }
    }

    if (ans == 0) lcm = 1;
    printf("%d %d\n", lcm, ans);
    vector<int> sto;
    forit(it1, d[lcm]) {
        forit(it2, v[*it1]) sto.pb(*it2);
    }
    sort(sto.begin(), sto.end());
    forit(it, sto) printf("%d ", *it);

    return 0;
}