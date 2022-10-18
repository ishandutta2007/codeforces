#include <bits/stdc++.h>
using namespace std;
#define debug(a) cout << #a << ": " << a << endl
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define ll long long
#define ii pair<int, int>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define maxN 4005
#define oo 1000000007

int n, v[maxN], d[maxN], p[maxN];
vector<int> ans;

int main() {
    bool left[maxN];
    memset(left, 0, sizeof(left));
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d%d%d", &v[i], &d[i], &p[i]);

    fto(i, 1, n) {
        if (!left[i]) {
            left[i] = true;
            queue<int> q;
            int j = i+1;
            while (v[i] > 0 && j <= n) {
                if (!left[j]) {
                    p[j]-=v[i];
                    --v[i];
                    if (p[j] < 0) {
                        q.push(j);
                        left[j] = true;
                    }
                }
                ++j;
            }
            while (!q.empty()) {
                int u = q.front(); q.pop();
                fto(v, u+1, n)
                    if (!left[v]) {
                        p[v]-=d[u];
                        if (p[v] < 0) {
                            q.push(v);
                            left[v] = true;
                        }
                    }
            }
            ans.pb(i);
        }
    }

    cout << ans.size() << endl;
    forit(it, vector<int>, ans) printf("%d ", *it);

    return 0;
}