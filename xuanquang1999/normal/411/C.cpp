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

int a[5][3];

bool Check_Team1() {
    int a1, d1, a2, d2;
    fto(i, 1, 2) {
        bool ok = true;
        a1 = a[i][1], d1 = a[3-i][2];
        fto(j, 3, 4) {
            a2 = a[j][1], d2 = a[7-j][2];
            if (a1 <= d2 || d1 <= a2) {
                ok = false;
                break;
            }
        }
        if (ok) return true;
    }
    return false;
}

bool Check_Team2() {
    int a1, d1, a2, d2;
    fto(i, 1, 2) {
        bool ok = false;
        a1 = a[i][1], d1 = a[3-i][2];
        fto(j, 3, 4) {
            a2 = a[j][1], d2 = a[7-j][2];
            if (a2 > d1 && d2 > a1) {
                ok = true;
                break;
            }
        }
        if (!ok) return false;
    }
    return true;
}


int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    fto(i, 1, 4)
        fto(j, 1, 2) scanf("%d", &a[i][j]);

    if (Check_Team1()) printf("Team 1");
    else if (Check_Team2()) printf("Team 2");
    else printf("Draw");

    return 0;
}