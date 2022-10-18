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
#define maxN 100005

int a, b;

int main () {
    //freopen("input.txt", "r", stdin);
    #ifdef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &a, &b);
    if (a == b) {
        fto(i, 1, b) printf("GB");
    }
    else if (a > b) {
        printf("B"); --a;
        fto(i, 1, b) printf("GB");
        fto(i, b+1, a) printf("B");
    }
    else {
        printf("G"); --b;
        fto(i, 1, a) printf("BG");
        fto(i, a+1, b) printf("G");
    }

    return 0;
}