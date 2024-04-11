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

int mon[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int day[7];
char s[100];
int main() {
        int i, j, n;
        scanf("%d %*s %s", &n, s);
        for(i = 4, j = 0; j < 7; i = (i + 1) % 7, j++)
                day[i] = j;
        int tot = 0;
        if(s[0] == 'm') {
                for(i = 0; i < 12; i++)
                        tot += mon[i] >= n;
        } else {
                int cur = day[n - 1] + 1;
                while(cur <= 366) cur += 7, tot++;
        }
        printf("%d\n", tot);
}