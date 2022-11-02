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

int a[1111];
int n;

void solve(int casi){
    //printf("Case #%d:", casi);
    scanf("%d", &n);
    int sm = 0;
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        sm += a[i];
    }
    int m = 1 << n;
    for (int i = 0; i < m; i++) {
        int u = 0;
        for (int j = 0; j < n; j++)
            if ((i >> j) & 1)
                u += a[j];
        int v = sm - u;
        u -= v;
        u = abs(u);
        u %= 360;
        if (u == 0){
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