//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define fordit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 200005

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

string s;
vector<string> ans[2];

bool check(string s) {
    int n = s.length();
    if (n == 0 || (n > 1 && s[0] == '0')) return true;
    fto(i, 0, n-1) {
        if (s[i] < '0' || s[i] > '9') return true;
    }
    return false;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    char c;
    while (scanf("%c", &c) != EOF) {
        if (c != '\n' && c != ',' && c != ';') s += c;
        else {
            ans[check(s)].pb(s);
            s = "";
        }
    }
    //ans[check(s)].pb(s);

    fto(i, 0, 1) {
        if (ans[i].size() == 0) puts("-");
        else {
            printf("\"");
            fto(j, 0, (int)ans[i].size()-2) cout << ans[i][j] << ",";
            cout << ans[i][ans[i].size()-1] << "\"";
            printf("\n");
        }
    }

    return 0;
}