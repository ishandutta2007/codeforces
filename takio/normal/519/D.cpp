#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 100100;

char s[N];
int v[26];
LL sum[N];
map <LL, int> mp[26];

int main () {
//    cout << 'x';
//    freopen ("in.txt", "r", stdin);
    for (int i = 0; i < 26; i++) scanf ("%d", &v[i]);
    scanf ("%s", s + 1);
    LL res = 0;
    for (int i = 1; s[i]; i++) {
        s[i] -= 'a';
        sum[i] = sum[i - 1] + v[s[i]];
        res += mp[s[i]][sum[i - 1]];
        mp[s[i]][sum[i]]++;
    }
    cout << res << endl;
}