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

const int N = 1010;
int n, m;
char s[N], t[N];
int ans, ansPos;

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    
    scanf("%d%d", &n, &m);
    scanf(" %s", s);
    scanf(" %s", t);

    ans = n + 1;
    ansPos = -1;
    for (int i = 0; i + n <= m; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++)
            cnt += (s[j] != t[i + j]);
        if (cnt < ans) {
            ans = cnt;
            ansPos = i;
        }
    }

    printf("%d\n", ans);
    for (int i = 0; i < n; i++)
        if (s[i] != t[ansPos + i])
            printf("%d ", i + 1);
    printf("\n");

    return 0;
}