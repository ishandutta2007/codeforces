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
#define maxN 100005

char s[maxN];
pair<char, int> ch[maxN];
int n;

bool cmp(pair<char, int> a, pair<char, int> b) {
    return ((a.fi < b.fi) || (a.fi == b.fi && a.se > b.se));
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%s", &s); n = strlen(s);
    fto(i, 0, n-1) ch[i] = mp(s[i], i);

    sort(ch, ch+n, cmp);

    int cur = -1;
    fdto(i, n-1, 0)
        if (ch[i].se > cur) {
            cur = ch[i].se;
            printf("%c", ch[i].fi);
        }

    return 0;
}