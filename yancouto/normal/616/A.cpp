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

char a[1000009], b[1000009];
int main() {
   scanf("%s %s", a, b);
   int nA = strlen(a), nB = strlen(b);
   int sA = 0, sB = 0;
   while(sA < nA && a[sA] == '0') sA++;
   while(sB < nB && b[sB] == '0') sB++;
   int sgn;
   if(nA - sA != nB - sB) sgn = (nA - sA) - (nB - sB);
   else if(sA == nA) sgn = 0;
   else sgn = strcmp(a + sA, b + sB);
   if(sgn < 0) puts("<");
   else if(sgn > 0) puts(">");
   else puts("=");
}