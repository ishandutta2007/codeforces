#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;

char s[MAXN];

void solve(int casi){
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    int cur = 0, boom = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'B') {
            if (cur > 0) {
                cur--; boom++;
            }
            else {
                cur++;
            }
        }
        else {
            cur++;
        }
    }
    printf("%d\n", cur);
}

int main(){
    int T = 1;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}