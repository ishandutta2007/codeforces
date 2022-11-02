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
        int n, kx, ky, k1 = 0, k2 = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
                int x;
                scanf("%d", &x);
                if (x % 2 == 0) {
                        k1++;
                        kx = i;
                } else {
                        k2++;
                        ky = i;
                }
        }
        if (k1 == 1)
                printf("%d\n", kx+1);
        else printf("%d\n", ky+1);
        return 0;
}