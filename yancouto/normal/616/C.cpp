#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
inline int id(int i, int j) { return i * 1000 + j; }
int S[1000009], sz[1000009];

int find(int i) {
   if(S[S[i]] != S[i]) S[i] = find(S[i]);
   return S[i];
}

inline void join(int a, int b) {
   if((a = find(a)) == (b = find(b))) return;
   if(sz[a] < sz[b]) swap(a, b);
   sz[a] += sz[b];
   S[b] = a;
}

char g[1003][1003], f[1003][1003];
int n, m;
inline bool valid(int i, int j) { return i >= 0 && j >= 0 && i < n && j < m; }
int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};

int main() {
   int i, j, d;
   for(i = 0; i < 1000009; i++)
       S[i] = i, sz[i] = 1;
   scanf("%d %d", &n, &m);
   for(i = 0; i < n; i++)
       scanf("%s", g[i]);
   for(i = 0; i < n; i++)
       for(j = 0; j < m; j++)
           if(g[i][j] == '.')
               for(d = 0; d < 4; d++) {
                   int ni = i + di[d], nj = j + dj[d];
                   if(!valid(ni, nj) || g[ni][nj] == '*') continue;
                   join(id(i, j), id(ni, nj));
               }
   for(i = 0; i < n; i++)
       for(j = 0; j < m; j++)
           if(g[i][j] == '.') f[i][j] = '.';
           else {
               set<int> s;
               for(d = 0; d < 4; d++) {
                   int ni = i + di[d], nj = j + dj[d];
                   if(!valid(ni, nj) || g[ni][nj] == '*') continue;
                   s.insert(find(id(ni, nj)));
               }
               int tot = 1;
               for(int x : s) tot += sz[x];
               f[i][j] = '0' + (tot % 10);
           }
   for(i = 0; i < n; i++)
       puts(f[i]);
}