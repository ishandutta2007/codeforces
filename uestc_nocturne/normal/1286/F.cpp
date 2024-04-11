/*
Author: elfness@UESTC
*/
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long LL;

const int V = 20;
const int oo = 1000000000;
LL ab(LL x) {if (x < 0) return -x; return x;}
LL a[V];
LL s[1 << V];
int c[1 << V];
int cost[1 << V];
int dp[1 << V];
//set<LL> ss[1 << V];
int n;
int main() {
    while (~scanf("%d", &n)) {
            /*
        for (int i = 0; i < (1 << n); ++i) {
            ss[i].clear();
        }*/
        for (int i = 0; i < n; ++i) scanf("%I64d", &a[i]);
        cost[0] = 0;
        for (int i = 0; i < (1 << n); ++i) {
            cost[i] = 0;
            s[i] = 0;
            c[i] = 0;
            int mid = 0;
            for (int j = 0; j < n; ++j) {
                if ((i & (1 << j))) {
                    if (a[j] != 0) ++cost[i];
                    s[i] += a[j];
                    ++c[i];
                    mid = j;
                }
            }
            if (c[i] >= 2) {
                /*
                for (int j = i - 1; j; j = (j - 1) & i) {
                    if (ab(s[j] - s[i ^ j]) % 2 != c[i] % 2 && ab(s[j] - s[i ^ j]) < c[i])
                        cost[i] = min(cost[i], c[i] - 1);
                }
                */
                if ((s[i] + c[i] - 1) % 2 == 0) {
                    LL mx = (s[i] + c[i] - 1) / 2;
                    LL mi = (s[i] - c[i] + 1) / 2;
                    //printf("%d %I64d %I64d\n", i, mi, mx);
                    for (int j = (i ^ (1 << mid)); j; j = (j - 1) & i) {
                        if (s[j] >= mi && s[j] <= mx) {
                            cost[i] = min(cost[i], c[i] - 1);
                            break;
                        }
                    }
                }
                /*
                if ((s[i] + c[i] - 1) % 2 == 0) {
                    for (int d = c[i] - 1; d >= 0; d -= 2) {
                        if (ss.find(s[i] + d) != ss.end()) {
                            cost[i] = min(cost[i], c[i] - 1);
                        }
                    }
                }
                */
            }
            //ss.insert(s[i]);
            //printf("C %d %d\n", i, cost[i]);
        }
        for (int i = 0; i < (1 << n); ++i) dp[i] = oo;
        dp[0] = 0;
        int sub = 0;
        for (int i = 1; i < (1 << n); ++i) {
            for (int j = i; j; j = (j - 1) & i) {
                dp[i] = min(dp[i], dp[i ^ j] + cost[j]);
                //++sub;
            }
        }
        //printf("%d\n", sub);
        printf("%d\n", dp[(1 << n) - 1]);
    }
    return 0;
}

/*
3
1 10 100
3
5 3 -2
1
0

15
1 1 1 1 1 1 1 1 1 1 1 1 1 1 2

16
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 2
17
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 2
18
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 2
19
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 2
20
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

*/