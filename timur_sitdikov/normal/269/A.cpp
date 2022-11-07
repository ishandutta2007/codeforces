#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex <double>
#define xx real()
#define yy imag()

const int maxn = 100005;
pair<int, int> m[maxn];

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, i, j, p, a, b;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d %d", &m[i].first, &m[i].second);
    }
    sort(m, m + n);
    p = 0;
    b = 0;
    a = m[0].second;
    for(i = 1; i < n; i++){
        for(j = 0; j < m[i].first - m[i - 1].first; j++){
            a = (a + 3) / 4;
            if (a == 1)
                break;
        }
        a = max(a, m[i].second);
    }
    for(j = m[i - 1].first; a > 1; j++)
        a = (a + 3) / 4;
    if (j == m[i - 1].first)
        j++;
    printf("%d", j);
}