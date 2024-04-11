#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
using namespace std;
int a[111111], lg[111111];
int g[22][111111];
int pw[33];
int n;
int gcd(int a, int b) {
    return b?gcd(b, a % b) : a;
}
int getGcd(int le, int ri) {
    if(ri >= n)
        return -1;
    int l(lg[ri - le + 1]);
    return gcd(g[l][le], g[l][ri - pw[l] + 1]);
}
map<int, long long> mp;
int main()
{
    scanf("%d", &n);
    for(int i(0); i < n; i++) {
        scanf("%d", &a[i]);
        g[0][i] = a[i];
    }
    lg[0] = -1;
    for(int i(1); i <= n; i++) {
        lg[i] = lg[i / 2] + 1;
    }
    pw[0] = 1;
    for(int i(1); i <= 20; i++)
        pw[i] = pw[i - 1] * 2;
    for(int i(1); i <= 17; i++) {
        for(int j(0); j + pw[i] <= n; j++)
            g[i][j] = gcd(g[i - 1][j], g[i - 1][j + pw[i - 1]]);
    }
    
    for(int i(0); i < n; i++) {
        int j(i);
        for(; j < n;) {
            int j1(j);
            for(int k(16); k >= 0; k--)
                if(getGcd(i, j) == getGcd(i, j1 + pw[k]))
                    j1 += pw[k];
            if(mp.count(getGcd(i, j1)))
                mp[getGcd(i, j1)] += j1 - j + 1;
            else
                mp[getGcd(i, j1)] = j1 - j + 1;
            j = j1 + 1;
        }
    }
    int q;
    scanf("%d", &q);
    for(int i(1); i <= q; i++) {
        int x;
        scanf("%d", &x);
        if(mp.count(x)) {
            printf("%I64d\n", mp[x]);
        }else {
            printf("%d\n", 0);
        }
    }
    return 0;
}