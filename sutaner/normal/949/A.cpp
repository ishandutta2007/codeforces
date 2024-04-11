#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector>
#define maxn 300005
#define pb push_back
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

char s[maxn];
int n, k = 0;
set<int> s0, s1;
set<int> :: iterator it;
vector<int> ans[maxn];

int main(){
    #ifndef ONLINE_JUDGE
        freopen("A.in", "r", stdin);
    #endif
    scanf("%s", s + 1);
    n = strlen(s + 1);
    int num0 = 0, num1 = 0;
    rep(i, 1, n){
        if (s[i] == '1') {
            num1++;
            s1.insert(i);
        }
        else {
            num0++;
            s0.insert(i);
        }
    }
    while (!s0.empty()){
        k++;
        int now = 0;
        now = *s0.lower_bound(now);
        ans[k].pb(now);
        s0.erase(now);
        while (1){
            it = s1.lower_bound(now);
            if (it == s1.end()) break;
            now = *it;
            it = s0.lower_bound(now); 
            if (it == s0.end()) break;
            ans[k].pb(now);
            s1.erase(now);
            now = *it;
            ans[k].pb(now);
            s0.erase(now);
        }
    }
    if (!s1.empty()) printf("-1");
    else {
        //for (it = s0.begin(); it != s0.end(); it++) ans[++k].pb(*it);
        printf("%d\n", k);
        rep(i, 1, k){
            int siz = ans[i].size();
            printf("%d ", siz);
            rep(j, 0, siz - 1) printf("%d ", ans[i][j]);
            printf("\n");
        }
    }
    return 0;
}