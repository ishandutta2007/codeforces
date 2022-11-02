//28D
#include<cstdio>
#include<map>
#include<algorithm>

using namespace std;

const int  N = 100005;

struct Key {
    int l, r;
    Key (const int t1 = 0, const int t2 = 0) {
        l = t1; r = t2;
    }
};

bool operator < (const Key &k1, const Key &k2) {
    if (k1.l < k2.l) { 
        return true;
    } else if (k1.l > k2.l) {
        return false;
    }
    return k1.r < k2.r;
}

int n, v[N], c[N], l[N], r[N], fa[N], cnt[N], ans, val[N];
bool flag;
Key tk;
map<Key, int> tree;
map<Key, int>::iterator it;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d %d", &v[i], &c[i], &l[i], &r[i]);
    }
    for (int i = n; i > 0; i--) {
        flag = false;
        if (r[i] == 0) {
            flag = true;
        } else {
            tk = Key(r[i], l[i] + c[i]);
            it = tree.find(tk);
            if (it != tree.end()) {
                flag = true;
                fa[i] = it->second;
            }
        }
        if (!flag) continue;
        val[i] = val[fa[i]] + v[i];
      cnt[i] = cnt[fa[i]] + 1;
        if (l[i] == 0) {
            if (val[i] > val[ans]) ans = i;
        } else {
            tk = Key(r[i] + c[i], l[i]);
            if ((it = tree.find(tk)) != tree.end()) {
                it->second = val[i] > val[it->second] ? i : it->second;
            } else {
              tree.insert(make_pair(tk, i));
          }
        }
    }
    printf("%d\n", cnt[ans]);
    for (int i = ans; i; i = fa[i]) printf("%d ", i);
  return 0;
}