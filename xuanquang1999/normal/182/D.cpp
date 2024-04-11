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
#define maxN 200005

char s1[maxN], s2[maxN];
int n1, n2, cnt;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%s", &s1); n1 = strlen(s1);
    scanf("%s", &s2); n2 = strlen(s2);

    fto(l, 1, n1)
        if (n1%l == 0 && n2%l == 0) {
            bool ok = true;
            fto(i, 0, n1-1)
                if (s1[i] != s1[i%l]) ok = false;
            fto(i, 0, n2-1)
                if (s2[i] != s1[i%l]) ok = false;
            if (ok) ++cnt;
        }

    printf("%d", cnt);

    return 0;
}