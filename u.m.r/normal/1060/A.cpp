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

void solve(int casi){
    //printf("Case #%d:", casi);
    int n;
    char s[111];
    scanf("%d", &n);
    scanf("%s", s);
    int cnt[100];
    for (int i = 0; i < 10; i++)
        cnt[i] = 0;
    for (int i = 0; i < n; i++){
        cnt[s[i] - '0']++;
    }
    printf("%d\n", min(n / 11, cnt[8]));
}

int main(){
    int T = 1;
    //scanf("%d", &T);
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}