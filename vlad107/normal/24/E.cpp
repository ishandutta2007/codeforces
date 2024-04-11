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

#define N 550000
#define INF 1000000000

int n;
double a[N], b[N], ll, rr;

int main() {    
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
                scanf("%lf%lf", &a[i], &b[i]);
	int k = 0;
	while (k < n && b[k] < 0) k++;
	while (k < n && b[k] > 0) k++;
	if (k == n) {
		puts("-1");
		return 0;
        }        
        ll = 0;
        rr = INF+INF;
        for (int qq = 0; qq < 100; qq++) {
                double m = (ll+rr)/2, c = -INF-INF;
                bool ok = false;
                for (int i = 0; i < n && !ok; i++) 
                        if (b[i] > 0) 
                                c = std::max(c, a[i]+b[i]*m);
                        else ok = (c >= a[i] + b[i]*m);
                if (ok)
                        rr = m;
                else ll = m;
        }
        if ((ll+rr)/2 > INF) 
		puts("-1");
	else printf("%.10lf", (ll+rr)/2);
        return 0;
}