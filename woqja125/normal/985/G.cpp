#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 200001;

vector<int> map[N];

int countrange(int idx, int l, int r) {
    return lower_bound(map[idx].begin(), map[idx].end(), r) - lower_bound(map[idx].begin(), map[idx].end(), l);
}

typedef unsigned long long ull;

ull sum(ull l, ull r) {
    ull n = r-l+1;
    return l*n + n*(n-1)/2; 
}

int n, m;
ull a, b, c;

const int R = 650;

int type[N];

ull get3() {
    ull ans = 0;
    vector<int> B;
    for(int i=0; i<n; i++)
        if(map[i].size() >= R) type[i] = 1, B.push_back(i);
        else type[i] = 0;
    for(int i=0; i<n; i++) {
        if(type[i] == 1) continue;
        for(int j=0; j<map[i].size(); j++) if(map[i][j] > i) {
            int e = map[i][j];
            for(int k=j+1; k<map[i].size(); k++) {
                if(binary_search(map[e].begin(), map[e].end(), map[i][k])) {
                    ans += a * i + b * e + c * map[i][k];
                }
            }
        }
    }

    for(int i=0; i<n; i++) for(auto e: map[i]) {
        if(i>e) continue;
        for(auto ee:B) {
            if(ee > i) break;
            if(!binary_search(map[i].begin(), map[i].end(), ee)) continue;
            if(!binary_search(map[e].begin(), map[e].end(), ee)) continue;
            ans += a * ee + b * i + c * e;
        }
    }

    return ans;
}

ull C2(ull x) {
    return x*(x-1)/2;
}

int main() {
    ull ans = 0;
    scanf("%d%d", &n, &m);
    scanf("%llu%llu%llu", &a, &b, &c);
    for(int i=0; i<n; i++) {
        ans += a * i * C2(n-i-1);
        ans += b * i * ((n-i-1llu) * i);
        ans += c * i * C2(i);
    }
    for(int i=0; i<m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        map[x].push_back(y);
        map[y].push_back(x);
        if(x > y) x^=y^=x^=y;
        ans -= a * sum(0, x-1);
        ans -= b * sum(x+1, y-1);
        ans -= c * sum(y+1, n-1);
        ans -= a * x * (n-x-2);
        ans -= b * x * (x);
        ans -= b * y * (n-y-1);
        ans -= c * y * (y-1);
    }
    
    for(int i=0; i<n; i++) sort(map[i].begin(), map[i].end());

    for(int i=0; i<n; i++) {
        ull cl = 0, cr = 0;
        for(int j=0; j<map[i].size(); j++) {
            if(map[i][j] < i) {
                ans += a * map[i][j] * (map[i].size() - j - 1llu);
                ans += b * map[i][j] * (j);
                cl++;
            }
            else {
                ans += b * map[i][j] * (map[i].size() - j - 1llu);
                ans += c * map[i][j] * (j);
                cr++;
            }
        }
        ans += a * i * C2(cr);
        ans += b * i * cr * cl;
        ans += c * i * C2(cl);
    }

    ans -= get3();

    printf("%llu\n", ans);

    return 0;
}