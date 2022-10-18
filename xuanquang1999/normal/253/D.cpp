using namespace std;
#include <bits/stdc++.h>
#define debug(a) cout << #a << ": " << a << endl
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 405

int cnta[maxN][maxN], n, m, k;
char a[maxN][maxN];
vector<int> p[256];
ll ans;

int CNTA(int x1, int y1, int x2, int y2) {
    return cnta[x2][y2]-cnta[x1-1][y2]-cnta[x2][y1-1]+cnta[x1-1][y1-1];
}

int TRINUM(int a) {
    return (a*(a-1))/2;
}

int main () {
    //freopen("input.txt", "r", stdin);
    #ifdef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d\n", &n, &m, &k);
    fto(i, 1, n) {
        int sum = 0;
        fto(j, 1, m) {
            scanf("%c", &a[i][j]);
            sum+=(a[i][j] == 'a');
            cnta[i][j] = cnta[i-1][j]+sum;
        }
        scanf("\n");
    }

    fto(x1, 1, n)
        fto(x2, x1+1, n) {
            fto(i, 'a', 'z') p[i].clear();
            fto(j, 1, m)
                if (a[x1][j] == a[x2][j]) p[a[x1][j]].pb(j);

            fto(i, 'a', 'z')
                if (p[i].size() > 0) {
                    int l = 0;
                    fto(r, 0, p[i].size()-1) {
                        while (l <= r && CNTA(x1, p[i][l], x2, p[i][r]) > k) ++l;
                        ans+=max(0, r-l);
                    }
                }
        }

    cout << ans;

    return 0;
}