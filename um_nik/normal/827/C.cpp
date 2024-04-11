#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 100010;
const int K = 4;
const int L = 10;
const int M = L * (L + 1) / 2;
int fenv[K * M][N];

void fenvAdd(int k, int p, int val)
{
    for (; p < N; p |= (p + 1))
        fenv[k][p] += val;
    return;
}
int fenvGet(int k, int r)
{
    int res = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        res += fenv[k][r];
    return res;
}
int getSum(int k, int l, int r)
{
    return fenvGet(k, r - 1) - fenvGet(k, l - 1);
}

char s[N];
char p[20];
int n;
int q;

int getId(char c, int len, int m)
{
    int cc = 0;
    if (c == 'A')
        cc = 0;
    else if (c == 'C')
        cc = 1;
    else if (c == 'G')
        cc = 2;
    else if (c == 'T')
        cc = 3;
    else
        throw;
    return cc * M + len * (len - 1) / 2 + m;
}

void changeChar(int pos, char c, int d)
{
    for (int len = 1; len <= L; len++) {
        fenvAdd(getId(c, len, pos % len), pos / len, d);
    }
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%s", s);
    n = strlen(s);
    for (int i = 0; i < n; i++)
        changeChar(i, s[i], +1);
    scanf("%d", &q);
    while(q--) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int pos;
            char c;
            scanf("%d %c", &pos, &c);
            pos--;
            changeChar(pos, s[pos], -1);
            s[pos] = c;
            changeChar(pos, s[pos], +1);
        } else {
            int l, r;
            scanf("%d%d %s", &l, &r, p);
            l--;
            int len = strlen(p);
            int ans = 0;
            for (int i = 0; i < len; i++) {
                int m = (l + i) % len;
                int lll = (l + i) / len;
                int rr = r / len;
                if (rr * len + m < r) rr++;
                ans += getSum(getId(p[i], len, m), lll, rr);
            }
            printf("%d\n", ans);
        }
    }

    return 0;
}