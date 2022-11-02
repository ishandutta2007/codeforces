#include <cstdio>
#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <bitset>
#include <ctime>
#define LL long long
#define pii pair <int, int>
#define ULL unsigned long long
using namespace std;

const int N = 20;
int a[N], l[N], r[N];
double res;

int main () {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
    }
    for (int i = 1; i <= 10000; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                double tmp;
                if (j == k || r[j] < i || r[k] < i || l[k] > i) continue;
                if (l[j] > i) tmp = 1.0;
                else if (k < j) tmp = 1.0 * (r[j] - i + 1) / (r[j] - l[j] + 1);
                else tmp = 1.0 * (r[j] - i) / (r[j] - l[j] + 1);
                tmp = tmp / (r[k] - l[k] + 1);
                for (int t = 1; t <= n; t++)
                if (t != j && t != k && l[t] > i) tmp = 0;
                else if (t != j && t != k && r[t] >= i){
                    if (t < k) tmp = tmp * (i - l[t] + 1) / (r[t] - l[t] + 1);
                    else tmp = tmp * (i - l[t]) / (r[t] - l[t] + 1);
                }
                res += i * tmp;
            }
        }
    }
    printf ("%.12f", res);
}