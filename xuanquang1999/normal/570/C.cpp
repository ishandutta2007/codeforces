using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
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
#define maxN 300005

int n, m, ans;
set<int> s;
char a[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    scanf("%s", a);
    s.insert(-1);
    s.insert(n);
    ans = n-1;
    fto(i, 0, n-1)
        if (a[i] != '.') {
            s.insert(i);
            int l = *(--s.find(i)), r = *(++s.find(i));
            ans = ans - max(0, r-l-2) + max(0, i-l-2) + max(0, r-i-2);
        }
    fto(iq, 1, m) {
        int i; char c;
        scanf("%d %c\n", &i, &c); --i;
        if (c == '.') {
            if (s.find(i) != s.end()) {
                int l = *(--s.find(i)), r = *(++s.find(i));
                ans = ans + max(0, r-l-2) - max(0, i-l-2) - max(0, r-i-2);
                s.erase(i);
            }
        }
        else {
            if (s.find(i) == s.end()) {
                s.insert(i);
                int l = *(--s.find(i)), r = *(++s.find(i));
                ans = ans - max(0, r-l-2) + max(0, i-l-2) + max(0, r-i-2);
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}