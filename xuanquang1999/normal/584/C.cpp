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
#define maxN 200005
#define MOD 1000000007
int n, t, t1, t2;
char a[maxN], b[maxN], c[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%s%s", &n, &t, a, b);
    t = n-t;
    fto(i, 0, n-1) c[i] = '?';
    fto(i, 0, n-1)
        if (t > 0 && a[i] == b[i]) {
            c[i] = a[i];
            --t;
        }

    t1 = t2 = t;
    fto(i, 0, n-1)
        if (a[i] != b[i]) {
            if (t1 > 0) c[i] = a[i], --t1;
            else if (t2 > 0) c[i] = b[i], --t2;
            else {
                fto(ch, 'a', 'z')
                    if (ch != a[i] && ch != b[i]) {
                        c[i] = ch;
                        break;
                    }
            }
        }

    if (t1 > 0 || t2 > 0) {
        puts("-1");
        return 0;
    }

    fto(i, 0, n-1)
        if (c[i] == '?') {
            fto(ch, 'a', 'z')
                if (ch != a[i] && ch != b[i]) {
                    c[i] = ch;
                    break;
                }
        }

    printf("%s", c);

    return 0;
}