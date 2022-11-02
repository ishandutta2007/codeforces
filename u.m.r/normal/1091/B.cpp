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

int n;
struct Pt{
    int x, y;
} ;
PII b[MAXN], a[MAXN];

void solve(int casi){
    //printf("Case #%d:", casi);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &a[i].first, &a[i].second);
    for (int i = 0; i < n; i++) 
        scanf("%d%d", &b[i].first, &b[i].second);
    sort(a, a + n);
    sort(b, b + n);
    for (int i = 0; i < n; i++) {
        // p[0] = i
        int Tx = a[i].first + b[0].first;
        int Ty = a[i].second + b[0].second;
        vector<PII> c(n);
        for (int j = 0; j < n; j++)
            c[j] = PII(Tx - b[j].first, Ty - b[j].second);
        sort(c.begin(), c.end());
        int flag = 1;
        for (int j = 0; j < n; j++)
            if (a[i] != c[i]){
                flag = 0;
                break;
            }
        if (flag) {
            printf("%d %d\n", Tx, Ty);
            return ;
        }
    }
}

int main(){
    int T = 1;
    //scanf("%d", &T);
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}