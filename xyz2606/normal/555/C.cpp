#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
const int N(811111);
int n;
int qx[N], posi[N];
char q[N], st[N];
struct SegmentTree {
    int v[N];
    SegmentTree() {
        for(int i(0); i < N; i++) {
            v[i] = -1e9;
        }
    }
    void change(int k, int le, int ri, int ql, int qr, int val) {
        if(le > qr || ql > ri) {
            return;
        }else if(ql <= le && ri <= qr) {
            v[k] = max(v[k], val);

            //printf("%d %d %d %d %d\n", le, ri, ql, qr, val);
        }else {
            int mid(le + ri >> 1);
            change(k + k, le, mid, ql, qr, val);
            change(k + k + 1, mid + 1, ri, ql, qr, val);
        }
    }
    void change(int le, int ri, int val) {
        //printf("change %d %d %d\n", le, ri, val);
        change(1, 1, n, le, ri, val);
    }
    int get(int k, int le, int ri, int posi) {
        if(le == posi && posi == ri) {
            return v[k];
        }else {
            int mid(le + ri >> 1);
            v[k + k] = max(v[k + k], v[k]);
            v[k + k + 1] = max(v[k + k + 1], v[k]);
            if(posi <= mid) {
                return get(k + k, le, mid, posi);
            }else {
                return get(k + k + 1, mid + 1, ri, posi);
            }
        }
    }
    int get(int posi) {
        return get(1, 1, n, posi);
    }
} up, left;
int main() {
    int m;
    scanf("%d%d", &n, &m);
    map<int, int> mp;
    for(int i(1); i <= m; i++) {
        scanf("%d%*d%s", &qx[i], st);
        q[i] = st[0];
        mp[qx[i]];
    }
    int tot(0);
    for(map<int, int>::iterator itr(mp.begin()); itr != mp.end(); itr++) {
        itr->second = ++tot;
        posi[tot] = itr->first;
    }
    posi[0] = 0;
    posi[tot + 1] = n + 1;
    n = tot;
    up.change(1, n, -n - 1);
    left.change(1, n, 0);
    for(int i(1); i <= m; i++) {
        int x;
        x = qx[i];
        st[0] = q[i];
        if(st[0] == 'U') {
            int xx(mp[x]);
            int tmp(posi[-up.get(xx)] - x);
            printf("%d\n", tmp);
            map<int, int>::iterator itr(mp.upper_bound(x + tmp - 1));
            if(itr != mp.begin()) {
                itr--;
                left.change(xx, itr->second, xx);
            }
            up.change(xx, xx, -xx);
        }else {
            int xx(mp[x]);
            int tmp(x - posi[left.get(xx)]);
            printf("%d\n", tmp);
            map<int, int>::iterator itr(mp.lower_bound(x - tmp + 1));
            if(itr != mp.end()) {
                up.change(itr->second, xx, -xx);
            }
            left.change(xx, xx, xx);
        }
    }
}