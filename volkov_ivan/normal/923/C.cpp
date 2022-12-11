#include <iostream>
 
using namespace std;

struct vertex{
    int prev, zero, one, cnt;
    vertex() {}
    vertex(int prev, int zero, int one, int cnt) {
        this->prev = prev;
        this->zero = zero;
        this->one = one;
        this->cnt = cnt;
    }
};

struct bytes{
    int b[30];
    bytes() {}
};

const int MAX_N = 1e7;
vertex bor[MAX_N];
int tail = 0;

bytes to_bytes(int n) {
    int last = 29;
    bytes ans;
    while (n >= 2) {
        ans.b[last] = (n % 2);
        n /= 2;
        last--;
    }
    ans.b[last] = n;
    last--;
    for (int i = last; i >= 0; i--) {
        ans.b[i] = 0;
    }
    return ans;
}

void add(int num) {
    bytes now = to_bytes(num);
    int v = 0;
    bor[v].cnt++;
    for (int i = 0; i < 30; i++) {
        if (now.b[i] == 0) {
            if (bor[v].zero == -1) {
                bor[v].zero = ++tail;
                bor[tail] = vertex(v, -1, -1, 0);
            }
            v = bor[v].zero;
            bor[v].cnt++;
        } else {
            if (bor[v].one == -1) {
                bor[v].one = ++tail;
                bor[tail] = vertex(v, -1, -1, 0);
            }
            v = bor[v].one;
            bor[v].cnt++;
        }
    }
}

void del(int v) {
    while (v != 0) {
        bor[v].cnt--;
        v = bor[v].prev;
    }
    bor[v].cnt--;
}

int main() {
    int n;
    scanf("%d\n", &n);
    int a[n], p[n], ans[n];
    for (int i = 0; i < n; i++) {
        scanf("%d ", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d ", &p[i]);
    }
    bor[0] = vertex(-1, -1, -1, 0);
    for (int i = 0; i < n; i++) {
        add(p[i]);
    }
    int need, v, num;
    for (int i = 0; i < n; i++) {
        v = 0;
        num = 0;
        for (int j = 29; j >= 0; j--) {
            need = a[i] & (1 << j);
            if (need == 0) {
                if (bor[v].zero == -1 || bor[bor[v].zero].cnt == 0) {
                    v = bor[v].one;
                    num |= (1 << j);
                } else {
                    v = bor[v].zero;
                }
            } else {
                if (bor[v].one == -1 || bor[bor[v].one].cnt == 0) {
                    v = bor[v].zero;
                } else {
                    v = bor[v].one;
                    num |= (1 << j);
                }
            }
        }
        ans[i] = a[i] ^ num;
        del(v);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}