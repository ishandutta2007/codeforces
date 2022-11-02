#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
#define ULL unsigned long long
using namespace std;

const int N = 1010;

char s[N];
int c[330];

int main() {
//    freopen ("in.txt", "r", stdin);
    int n, cnt = 0;
    cin >> n;
    scanf ("%s", s + 1);
    for (int i = 1; i <= n; i++) {
        if (c[s[i]] == 0) cnt++;
        c[s[i]]++;
    }
    if (cnt == 1) {
        cout << s[1];
    } else if (cnt == 3) {
        cout << "BGR";
    } else {
        if (c['B'] + c['G'] + c['R'] == 2) {
            char ch = 'B' + 'G' + 'R';
            if (c['B']) ch -= 'B';
            if (c['G']) ch -= 'G';
            if (c['R']) ch -= 'R';
            cout << ch << endl;
        } else if (c['B'] == 1 || c['G'] == 1 || c['R'] == 1) {
            if (c['B'] > 1) cout << "GR";
            if (c['G'] > 1) cout << "BR";
            if (c['R'] > 1) cout << "BG";
        } else cout << "BGR";
    }
    return 0;
}