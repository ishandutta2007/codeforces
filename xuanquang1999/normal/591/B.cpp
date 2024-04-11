using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define fordit(rit, type, var) for(type::reverse_iterator rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 200005

int ch[256], n, m;
char s[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    scanf("%s\n", s);
    fto(c, 'a', 'z') ch[c] = c;
    fto(i, 1, m) {
        char x, y;
        scanf("%c %c\n", &x, &y);
        char p1, p2;
        fto(c, 'a', 'z')
            if (ch[c] == y) p1 = c;
        fto(c, 'a', 'z')
            if (ch[c] == x) p2 = c;
        ch[p1] = x; ch[p2] = y;
    }

    fto(i, 0, n-1) s[i] = ch[s[i]];

    printf("%s", s);

    return 0;
}