#include <cstdio>
#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#define LL long long
#define pii pair <int, int>
using namespace std;

const int N = 110;
char s[N][N];
int mp[30][30], cnt[30], res[30];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf ("%s", s[i]);
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 0; s[i][j] != 0 || s[i - 1][j] != 0; j++) {
            if (!s[i - 1][j]) break;
            if (!s[i][j]) {
                cout << "Impossible\n";
                return 0;
            }
            if (s[i][j] != s[i - 1][j]) {
                if (!mp[s[i - 1][j] - 'a'][s[i][j] - 'a']) {
                    mp[s[i - 1][j] - 'a'][s[i][j] - 'a'] = 1;
//                cout << s[i - 1][j] << ' '<< s[i][j] << endl;
                    cnt[s[i][j] - 'a']++;
                }
                break;
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        int j;
        for (j = 0; j < 26; j++) {
            if (cnt[j] == 0) {
                cnt[j] = -1;
                res[i] = j;
                for (int k = 0; k < 26; k++) {
                    if (mp[j][k]) cnt[k]--;
                }
                break;
            }
        }
        if (j == 26) {
            cout << "Impossible\n";
            return 0;
        }
    }
    for (int i = 0; i < 26; i++) cout << (char)(res[i] + 'a');
}