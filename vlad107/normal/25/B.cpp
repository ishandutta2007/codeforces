#include <algorithm>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <memory>
#include <limits>
#include <queue>
#include <deque>
#include <bitset>
#include <stack>
#include <numeric>
#include <cmath>
#include <complex>
#include <list>
#include <ctime>

int main() {
        int n;
        char a[1000];
        scanf("%d\n", &n);      
        for (int i = 0; i < n; i++)
                a[i] = getchar();
        if (n % 2 == 0) {
                for (int i = 0; i < n; i++) {   
                        putchar(a[i]);
                        if (i == n-1) break;
                        if (i & 1) putchar('-');
                }
        } else {
                for (int i = 0; i < n-3; i++) {
                        putchar(a[i]);
                        if (i & 1) putchar('-');
                }
                for (int i = n-3; i < n; i++)
                        putchar(a[i]);
        }
        return 0;
}