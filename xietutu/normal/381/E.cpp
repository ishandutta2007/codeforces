#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
const int maxn = 1000005;
char s[maxn];
bool right[maxn];
int n,m,last,ans[maxn],tree[maxn],pos[maxn];
std::stack<int> Q;
struct arr {
    int l,r,no;
} a[maxn];
bool operator<(const arr& lhs,const arr& rhs) {
    return lhs.r < rhs.r;
}
void prepare() {
    for (int i = 1; i <= n; ++i) 
        if (s[i] == '(') Q.push(i);
        else {
            if (Q.size()) {
                pos[i] = Q.top();
                Q.pop();
            }
        }
}
void add(int x) {
    while (x <= n) {
        ++tree[x]; x += x & (-x);
    }
}
int query(int x) {
    int s = 0;
    while (x) {
        s += tree[x]; x -= x & (-x);
    }
    return s;
}        
int main() {
    scanf("%s",s + 1);
    n = strlen(s + 1);
    prepare();
    scanf("%d",&m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d",&a[i].l,&a[i].r);
        a[i].no = i;
    }
    std::sort(a + 1, a + m + 1);  
    int now = 0;     
    for (int i = 1; i <= n; ++i) {
        if (pos[i]) add(pos[i]);
        int r = query(i);
        while (now < m && a[now + 1].r == i) {
            ++now; 
            ans[a[now].no] = r - query(a[now].l - 1);
        }
    }
    for (int i = 1; i <= m; ++i) printf("%d\n",ans[i] * 2);
}