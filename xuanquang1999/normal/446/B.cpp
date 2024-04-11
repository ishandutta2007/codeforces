using namespace std;
#include <bits/stdc++.h>
#define debug(a) cout << #a << ": " << a << endl
#define fdto(i, r, l) for(ll i = r; i >= l; --i)
#define fto(i, l, r) for(ll i = l; i <= r; ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 1005
#define maxK 1000005
#define oo 1000000000000000007

int a[maxN][maxN];
ll n, m, k, p, fr[maxK], fc[maxK], ans;
multiset<int> s;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n >> m >> k >> p;
    fto(i, 0, n-1)
        fto(j, 0, m-1) scanf("%d", &a[i][j]);

    s.clear();
    fto(i, 0, n-1) {
        int sum = 0;
        fto(j, 0, m-1) sum+=a[i][j];
        s.insert(sum);
    }
    fto(i, 1, k) {
        multiset<int>::iterator it = --s.end();
        fr[i] = fr[i-1]+(*it);
        s.erase(it); s.insert((*it)-m*p);
    }

    s.clear();
    fto(j, 0, m-1) {
        int sum = 0;
        fto(i, 0, n-1) sum+=a[i][j];
        s.insert(sum);
    }
    fto(i, 1, k) {
        multiset<int>::iterator it = --s.end();
        fc[i] = fc[i-1]+(*it);
        s.erase(it); s.insert((*it)-n*p);
    }

    ans = -oo;
    fto(i, 0, k)
        ans = max(ans, fr[i]+fc[k-i]-i*(k-i)*p);

    cout << ans;

    return 0;
}