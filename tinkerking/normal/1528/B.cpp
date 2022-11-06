#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

const int MOD = 998244353;
int n;
int f[2000010], s[2000010];
//vector<int> fac[2000010];
int cnt[2000010];

void upd(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

int main() {
    scanf("%d",&n);
    for (int i = 2; i <= 2 * n; i += 2) {
        for (int j = i; j <= 2 * n; j += i) {
            //fac[j].push_back(i);
            cnt[j]++;
        }
    }
    f[2] = 1;
    s[2] = 1;
    for (int i = 4; i <= 2 * n; i += 2) {
        f[i] = 0;
        //upd(f[i], fac[i].size());
        upd(f[i], cnt[i]);
        upd(f[i], s[i - 2]);
        s[i] = s[i - 2];
        upd(s[i], f[i]);
    }
    printf("%d\n",f[2 * n]);
}