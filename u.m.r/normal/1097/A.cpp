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

char s[100], t[111];

void solve(int casi){
    //printf("Case #%d:", casi);
    scanf("%s", s);
    for (int i = 0; i < 5; i++) {
        scanf("%s", t);
        if (t[0] == s[0] || t[1] == s[1]) {
            puts("YES");
            return ;
        }
    }
    puts("NO");
    return ;
}

int main(){
    int T = 1;
    //scanf("%d", &T);
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}