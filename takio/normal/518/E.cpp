#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#define LL long long
#define pii pair <int, int>
using namespace std;

const int INF = 2e9, N = 100100;
int a[N], t[N], tn;

inline LL read()
{
    char ch=getchar();LL x=0,f=1;
    while(ch>'9'||ch<'0'){if(ch=='?')return INF; if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

LL cal (LL x, LL num) {
    if (x < 0) {
        x = -x;
        if (x < num) return x * (x + 1) / 2 + (num - x - 1) * (num - x) / 2;
        return (2 * x - num + 1) * num / 2;
    }
    return (x * 2 + num - 1) * num / 2;
}

int solve () {
//    for (int i = 1; i <= tn; i++) cout << a[t[i]] << ' '; cout << endl;
    int cnt = 0, i = 1, f, tmp;
    while (i <= tn && a[t[i]] == INF) cnt++, i++;
    f = a[t[i]];
    if (cnt) {
        if (i > tn) {
            for (int i = 1, tmp = -cnt / 2; i <= tn; i++, tmp++) a[t[i]] = tmp;
            return 1;
        }
        if ((cnt - 1) / 2 < f) {
            tmp = (cnt - 1) / 2;
        } else {
            tmp = f - 1;
        }
        for (int k = i - 1; k >= 1; k--, tmp--) a[t[k]] = tmp;
        cnt = 0;
    }
    i++;
    for (; i <= tn; i++) {
        if (a[t[i]] != INF) {
            if (a[t[i]] - f < cnt + 1) return 0;
            if (cnt) {
                int l = -cnt / 2, r = (cnt - 1) / 2;
                if (f < l && a[t[i]] > r) {
                    for (int k = i - cnt; k < i; k++, l++) a[t[k]] = l;
                } else {
                    LL ll = cal (f + 1, cnt), rr = cal (a[t[i]] - cnt, cnt);
                    if (ll < rr) {
                        for (int k = i - cnt, l = f + 1; k < i; k++, l++) a[t[k]] = l;
                    } else {
                        for (int k = i - cnt, l = a[t[i]] - cnt; k < i; k++, l++) a[t[k]] = l;
                    }
                }
            }
            f = a[t[i]], cnt = 0;
        } else {
            cnt++;
        }
    }
    if (cnt) {
        if (f < -cnt / 2) {
            tmp = -cnt / 2;
        } else {
            tmp = f + 1;
        }
        for (int k = tn - cnt + 1; k <= tn; k++, tmp++) a[t[k]] = tmp;
    }
    return 1;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        a[i] = read();
    }
    for (int i = 1; i <= k; i++) {
        tn = 0;
        for (int j = i; j <= n; j += k) {
            t[++tn] = j;
        }
        if (!solve ()) {
            printf ("Incorrect sequence\n");
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) printf ("%d ", a[i]);
}