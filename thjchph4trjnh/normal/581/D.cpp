#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORd(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

vector<pair<pair<int, int>, int> > v;

void solve() {
    char name[] = "ABC";
    int area = 0;
    FOR(i, 0, 3) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x < y) swap(x, y);
        v.push_back(make_pair(make_pair(x, y), i));
        area += x * y;
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    int k = (int) sqrt(area);
    if (k * k < area) k++;
    if (k * k > area || v[0].first.first != k) {printf("-1"); return;}
    if (v[1].first.first == k && v[2].first.first == k) {
        printf("%d\n", k);
        FOR(i, 0, v[0].first.second) {
            FOR(j, 0, k) printf("%c", name[v[0].second]);
            printf("\n");
        }
        FOR(i, 0, v[1].first.second) {
            FOR(j, 0, k) printf("%c", name[v[1].second]);
            printf("\n");
        }
        FOR(i, 0, v[2].first.second) {
            FOR(j, 0, k) printf("%c", name[v[2].second]);
            printf("\n");
        }
        return;
    }
    printf("%d\n", k);
    FOR(i, 1, 3) {
        if (v[i].first.second != k - v[0].first.second) {
            int tmp = v[i].first.second;
            v[i].first.second = v[i].first.first;
            v[i].first.first = tmp;
        }
        if (v[i].first.second != k - v[0].first.second) {printf("-1"); return;}
    }
    FOR(i, 0, v[0].first.second) {
        FOR(j, 0, k) printf("%c", name[v[0].second]);
        printf("\n");
    }
    FOR(i, v[0].first.second, k) {
        FOR(j, 0, k) {
            if (j < v[1].first.first) printf("%c", name[v[1].second]);
            else printf("%c", name[v[2].second]);
        }
        printf("\n");
    }
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}