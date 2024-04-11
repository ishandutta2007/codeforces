using namespace std;
#include <bits/stdc++.h>
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
#define maxN 1505
#define hashmod 100003
char a[maxN], isbad[27];
int ord[maxN], n, k, ans;
vector<int> _hash[hashmod];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%s", &a); n = strlen(a);
    scanf("%s", &isbad);
    fto(i, 0, n-1) ord[i] = a[i]-96;
    fdto(i, 26, 1) isbad[i]=49-isbad[i-1];
    scanf("%d", &k);

    fto(l, 1, n) {
        fto(i, 0, hashmod-1) _hash[i].clear();
        int cur = 0, bad = 0, e26 = 1;
        fto(i, 0, l-1) {
            cur = (26*cur+ord[i])%hashmod;
            bad+=isbad[ord[i]];
        }
        fto(i, 0, l-2) e26 = (e26*26)%hashmod;

        fto(i, l, n) {
            if (bad <= k) {
                bool toadd = true;
                forit(it, vector<int>, _hash[cur]) {
                    bool found = true;
                    fto(j, 0, l-1)
                        if (a[i-l+j] != a[*it+j]) {
                            found = false;
                            break;
                        }
                    if (found) {
                        toadd = false;
                        break;
                    }
                }
                if (toadd) {
                    ++ans;
                    _hash[cur].pb(i-l);
                }
            }
            if (i == n) break;
            cur = ((cur+26*hashmod-ord[i-l]*e26)%hashmod*26+ord[i])%hashmod;
            bad = bad - isbad[ord[i-l]] + isbad[ord[i]];
        }
    }

    printf("%d", ans);

    return 0;
}