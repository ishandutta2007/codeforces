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

map<int, int> mp1, mp2;
char s[MAXN];

void solve(int casi){
    //printf("Case #%d:", casi);
    int n;
    scanf("%d", &n);
    int ans = 0;
    int p0 = 0;
    for (int k = 0; k < n; k++) {
        scanf("%s", s);
        int cnt = 0, flag = 1;
        int m = strlen(s);
        for (int i = 0; i < m; i++)
            if (s[i] == '(') {
                cnt++;
            }
            else {
                if (cnt > 0) cnt--;
                else {
                    flag = 0;
                    break;
                }
            }
        if (flag) {
            if (cnt == 0) p0++;
            else if (cnt > 0) mp1[cnt]++;
        }
        cnt = 0;
        flag = 1;
        for (int i = m - 1; i >= 0; i--)
            if (s[i] == ')') {
                cnt++;
            }
            else {
                if (cnt > 0) cnt--;
                else {
                    flag = 0;
                    break;
                }
            }
        if (flag) {
            if (cnt > 0) mp2[cnt]++;
        }
    }
    ans = p0 / 2;
    for (auto &x : mp1) {
        int cnt = x.first;
        int y = mp2[x.first];
        ans += min(y, x.second);
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