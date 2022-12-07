#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <set>
#define maxn 300005
#define bit 62
#define ll long long int
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxn, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char *p1, *p2;
char buffer[maxn];
template <class T> void read(T& x){
    char ch = gc(); x = 0; bool f = 1;
    while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
    if (ch == '-') f = 0, ch = gc();
    while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
    if (!f) x = -x;
}

ll n;
int k;
//int a[maxn];
ll q[maxn];
ll two[bit + 1];


/*set<int> s[maxn];

void BF(){
    for (int i = 1; i <= (n << 1) - 1; i += 2) a[i] = (i + 1) >> 1; 
    int now = (n << 1) - 1;
    int empty = (n << 1) - 2;
    while (empty){
        a[empty] = a[now];
        now--, empty -= 2;
    }
    rep(i, 1, (n << 1) - 1) printf("%d ", a[i]);
    printf("\n");
    rep(i, 1, (n << 1) - 1){
        s[a[i]].insert((n << 1) - 1 - i);
    }
    rep(i, 1, n){
        printf("%d: ", i);
        for (set<int> :: iterator it = s[i].begin(); it != s[i].end(); it++){
            printf("%d ", *it);
        }
        printf("\n");
    }
}*/

int main(){
    #ifndef ONLINE_JUDGE
        freopen("B.in", "r", stdin);
        //freopen("B.out", "w", stdout);
    #endif
    scanf("%I64d%d", &n, &k);
    two[0] = 1;
    rep(i, 1, bit) two[i] = two[i - 1] << 1;
    ll x;
    rep(i, 1, k) {
        scanf("%I64d", &x); 
        ll _x = x - 2 * n;
        rep(i, 0, bit){
            if (abs(_x + two[i]) % two[i + 1] == 0){
                printf("%I64d\n", n + (_x + two[i]) / two[i + 1]);
                goto jump;
            }
        }
        assert(false);
        jump:;
    }
    //BF();
    return 0;
}