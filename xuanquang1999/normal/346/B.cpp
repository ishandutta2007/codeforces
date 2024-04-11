#include <bits/stdc++.h>
using namespace std;

#define debug(a) cout << #a << ": " << a << endl
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define ftoa(i, l, r, a) for(int i = l; i <= r; i += a)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); ++it)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); ++rit)
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ii pair<int, int>
#define maxN 105

int calcP(string s, string t) {
//    debug(s);
//    debug(t);
    int l = min(s.length(), t.length());
    fdto(i, l, 1) {
        if (s.substr(s.length()-i) == t.substr(0, i)) return i;
    }
    return 0;
}

string s, t, virus;
int automat[maxN][256], f[maxN][maxN][maxN], trace[maxN][maxN][maxN];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> s >> t >> virus;

    fto(i, 0, virus.length()-1) {
        string s = virus.substr(0, i+1);
        fto(c, 'A', 'Z') {
            s[i] = c;
            automat[i][c] = calcP(s, virus);
        }
    }
//    fto(i, 0, virus.length()-1) {
//        fto(c, 'A', 'Z') printf("%d ", automat[i][c]);
//        puts("");
//    }
    fto(i, 0, s.length()) {
        fto(j, 0, t.length()) {
            fto(k, 0, virus.length()-1) trace[i][j][k] = -1;
        }
    }

    int maxLen = 0, ansI, ansJ, ansK;
    fto(i, 0, s.length()) {
        fto(j, 0, t.length()) {
            fto(k, 0, virus.length()-1) {
                if (i < s.length() && j < t.length()) {
                    int K = automat[k][s[i]];
                    if (s[i] == t[j] && K < virus.length() && f[i+1][j+1][K] < f[i][j][k]+1) {
                        f[i+1][j+1][K] = f[i][j][k]+1;
                        trace[i+1][j+1][K] = k;
                    }
                }
                if (i < s.length()) f[i+1][j][k] = max(f[i+1][j][k], f[i][j][k]);
                if (j < t.length()) f[i][j+1][k] = max(f[i][j+1][k], f[i][j][k]);
                if (f[i][j][k] > maxLen) {
                    maxLen = f[i][j][k];
                    ansI = i; ansJ = j; ansK = k;
                }
            }
        }
    }
    if (maxLen == 0) {
        puts("0");
        return 0;
    }

    int i = ansI, j = ansJ, k = ansK;
    string ans = "";
    while (i > 0 && j > 0) {
        if (f[i][j][k] == f[i-1][j][k]) --i;
        else if (f[i][j][k] == f[i][j-1][k]) --j;
        else {
            k = trace[i][j][k]; --i; --j;
            ans += s[i];
        }
    }

    reverse(ans.begin(), ans.end());

    cout << ans;

    return 0;
}