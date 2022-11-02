#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;


ll pw(ll p, ll q){
    ll ret = 1;
    for (; q; q >>= 1){
        if (q & 1)
            ret = ret * p % MM;
        p = p * p % MM;
    }
    return ret;
}

char s[1000];

void solve(int casi){
    //printf("Case #%d:", casi);
    scanf("%s", s);
    int n = strlen(s);
    int pre = 0, ans = 0;
    for (int i = n - 1; i >= 0; i--){
        int x = s[i] - '0' - pre;
        if (i && x != 9) x += 10, pre = 1;
        ans += x;
    }
    printf("%d\n", ans);
}

int main(){
    int T = 1;
    //scanf("%d", &T);
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}