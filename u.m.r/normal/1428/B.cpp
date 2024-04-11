#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;

int n;
int f[MAXN];
char s[MAXN];

void solve(int casi){
    scanf("%d", &n);
    scanf("%s", s);
    int p = 0, q = 0;
    for (int i = 0; i < n; i++) {
        f[i] = 0;
        if (s[i] == '>') p++;
        else if (s[i] == '<') q++;
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '-') {
            f[i] = 1;
            f[(i + 1) % n] = 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) ans += f[i];
    if (p == 0 || q == 0) ans = n;
    printf("%d\n", ans);
}

int main(){
    int T = 1;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}