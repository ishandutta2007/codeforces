#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<set>
#include<utility>
#include<deque>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<complex>
#include<ctime>
#include<cmath>
#include<list>
#include<map>
#include<utility>
#include<string>
#include<cstring>
#include<climits>

using namespace std;
typedef long long int lint;
typedef long double ldb;

const lint INF = 1e16;

int c[101][101];
int n, m;

int main() {
    scanf("%d%d", &n, &m);
    int ans = 0;
    for(int i = 0; i < n; i++){
        int cmin = 1e9 + 7;
        for(int j = 0; j < m; j++){
            int tmp;
            scanf("%d", &tmp);
            cmin = min(cmin, tmp);
        }
        ans = max(ans, cmin);

    }
    printf("%d", ans);
	return 0;
}