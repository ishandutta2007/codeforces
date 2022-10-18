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

string p[8] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
string s;
int l;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d\n", &l);
    cin >> s;
    //cout << s << endl;
    fto(i, 0, 7) {
        //printf("%d\n", i);
        if (s.length() != p[i].length()) continue;
        bool ok = true;
        fto(j, 0, s.length()-1)
            if (s[j] != '.' && s[j] != p[i][j]) {
                ok = false;
                break;
            }
        if (ok) cout << p[i];
    }

    return 0;
}