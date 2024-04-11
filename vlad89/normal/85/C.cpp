#define _CRT_SECURE_NO_DEPRECATE
#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <sstream>
#include <numeric>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <list>
#include <set>
#include <map>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define all(a) (a).begin(),(a).end()
#define UN(a) SORT(a),(a).resize(unique(all(a))-a.begin())
#define sz(a) ((int) (a).size())
#define pb push_back
#define CL(a,b) memset (a, b, sizeof (a))
#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

const int N = 123456;
const int Root = -2;

int parent[N], value[N];
int deg[N];
int st[N];
int mi[N], ma[N];
int l[N], r[N];
long long d[N];
int h[N];
pii v[N];
int L[N], R[N];
double ans[N];
int n,sz;

int main() {
    #ifdef LocalHost
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    scanf ("%d", &n);
    REP (i, n) {
        scanf ("%d", parent+i);
        scanf ("%d", value+i);
        parent[i]--;
        if (parent[i] != Root)
            deg[parent[i]]++;
    }
    REP (i, n) {
        if (deg[i] == 0) {
            st[sz++] = i;
            l[i] = -1;
        }
        mi[i] = value[i];
        ma[i] = value[i];        
    }
    for (int cr = 0; cr < sz; ++cr) {
        int g = st[cr];
        if (parent[g] != Root) {
            mi[parent[g]] = min (mi[parent[g]], mi[g]);
            ma[parent[g]] = max (ma[parent[g]], ma[g]);
            deg[parent[g]]--;
            if (deg[parent[g]] == 0) {
                st[sz++] = parent[g];
            }
            if (value[parent[g]] > value[g])
                l[parent[g]] = g;
            else
                r[parent[g]] = g;
        }                        
    }
    int k;
    scanf ("%d", &k);
    REP (i, k) {
        scanf ("%d", &v[i].X);
        v[i].Y = i;
    }
    sort(v, v+k);
    for (int i = sz-1; i >= 0; --i) {
        int g = st[i];
        if (parent[g] == Root) {
            L[g] = 0;
            R[g] = k;
        }
        if (l[g] == -1) {
            FOR (x, L[g], R[g])
                ans[v[x].Y] = (double) d[g] / h[g];
            continue;
        }
        d[l[g]] = d[g] + mi[r[g]];
        d[r[g]] = d[g] + ma[l[g]];
        h[l[g]] = h[g]+1;
        h[r[g]] = h[g]+1;
        
        if (L[g] != R[g]) {
            int x = lower_bound(v+L[g], v+R[g], pii(value[g], 0))-v;
            L[l[g]] = L[g];
            R[l[g]] = x;
            
            L[r[g]] = x;
            R[r[g]] = R[g];            
        }
    }    
    REP (i, k)
        printf ("%.9lf\n", ans[i]);
	return 0;
}