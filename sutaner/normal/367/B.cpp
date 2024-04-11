#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <set>
#define maxn 300005
#define LL long long int
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
using namespace std;

struct ele{
    int x, num;
    ele(int x, int num) : x(x), num(num){}
    ele(){}
    bool operator < (const ele b) const{
        return x < b.x;
    }
};

LL n, m, p;
int a[maxn], b[maxn];

set<ele> s;
set<ele> :: iterator it;

set<int> ans;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("215B.in", "r", stdin);
    #endif
    scanf("%I64d%I64d%I64d", &n, &m, &p);
    rep(i, 1, n) scanf("%d", &a[i]);
    rep(i, 1, m) scanf("%d", &b[i]);
    sort(b + 1, b + 1 + m); 

    rep(i, 1, p){
        if (i + (m - 1) * p > n) break;

        s.clear();

        rep(j, 1, m){
            int now = b[j];
            int num = 0;
            while (j <= m && b[j] == now) j++, num++;
            s.insert(ele(now, num));
            j--;
        }

        for (register int j = i; j <= i + (m - 1) * p; j += p){
            int now = a[j];
            it = s.lower_bound(ele(now, 0));
            if (it != s.end() && it -> x == now){
                ele op = *it;
                s.erase(it);
                op.num--;
                if (op.num) s.insert(op);
            }
            else s.insert(ele(now, -1)); 
        }

        if (s.empty()) ans.insert(i);
        for (register int j = i + m * p; j <= n; j += p){
            int now = a[j];
            it = s.lower_bound(ele(now, 0));
            if (it != s.end() && it -> x == now){
                ele op = *it;
                s.erase(it);
                op.num--;
                if (op.num) s.insert(op);
            }
            else s.insert(ele(now, -1)); 

            now = a[j - m * p];
            it = s.lower_bound(ele(now, 0));
            if (it != s.end() && it -> x == now){
                ele op = *it;
                s.erase(it);
                op.num++;
                if (op.num) s.insert(op);
            }
            else s.insert(ele(now, 1)); 

            if (s.empty()) ans.insert(j - (m - 1) * p);
        }
    }
    printf("%d\n", ans.size());
    for (set<int> :: iterator it = ans.begin(); it != ans.end(); it++) printf("%d ", *it);
    return 0;
}