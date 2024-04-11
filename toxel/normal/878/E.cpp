#include<bits/stdc++.h>

typedef long long ll;
typedef std::pair <int, int> pii;
const int N = 100010;
const int MAX = 1 << 17;
const int moder = 1e9 + 7;
const ll INF = 1e18;

int seg[MAX << 1], lazymult[MAX << 1], lazyadd[MAX << 1];

void addmod(int &a, int b){
    a += b;
    a -= a >= moder? moder : 0;
}

void submod(int &a, int b){
    a -= b;
    a += a < 0 ? moder : 0;
}

void multmod(int &a, int b){
    a = 1ll * a * b % moder;
}

void multadd(int &a, int b, int c){
    a = (a + 1ll * b * c) % moder;
}

void push(int sit, int l, int r){
    for (int i = 0; i < 2; ++ i){
        multmod(lazymult[sit << 1 | i], lazymult[sit]);
        multmod(lazyadd[sit << 1 | i], lazymult[sit]);
        multmod(seg[sit << 1 | i], lazymult[sit]);
        
        addmod(lazyadd[sit << 1 | i], lazyadd[sit]);
        multadd(seg[sit << 1 | i], r - l + 1 >> 1, lazyadd[sit]);
    }
    lazymult[sit] = 1;
    lazyadd[sit] = 0;
}

void pull(int sit){
    seg[sit] = seg[sit << 1];
    addmod(seg[sit], seg[sit << 1 | 1]);
}

void add(int sit, int l, int r, int ql, int qr, int value){
    if (ql <= l && qr >= r){
        multadd(seg[sit], r - l + 1, value);
        addmod(lazyadd[sit], value);
        return;
    }
    push(sit, l, r);
    int mid = l + r >> 1;
    if (ql <= mid){
        add(sit << 1, l, mid, ql, qr, value);
    }
    if (qr > mid){
        add(sit << 1 | 1, mid + 1, r, ql, qr, value);
    }
    pull(sit);
}

void add(int ql, int qr, int value){
    add(1, 0, MAX - 1, ql, qr, value);
}

void mult(int sit, int l, int r, int ql, int qr, int value){
    if (ql <= l && qr >= r){
        multmod(seg[sit], value);
        multmod(lazyadd[sit], value);
        multmod(lazymult[sit], value);
        return;
    }
    push(sit, l, r);
    int mid = l + r >> 1;
    if (ql <= mid){
        mult(sit << 1, l, mid, ql, qr, value);
    }
    if (qr > mid){
        mult(sit << 1 | 1, mid + 1, r, ql, qr, value);
    }
    pull(sit);
}

void mult(int ql, int qr, int value){
    mult(1, 0, MAX - 1, ql, qr, value);
}

int query(int sit, int l, int r, int ql, int qr){
    if (ql <= l && qr >= r){
        return seg[sit];
    }
    push(sit, l, r);
    int mid = l + r >> 1;
    int ans = 0;
    if (ql <= mid){
        addmod(ans, query(sit << 1, l, mid, ql, qr));
    }
    if (qr > mid){
        addmod(ans, query(sit << 1 | 1, mid + 1, r, ql, qr));
    }
    return ans;
}

int query(int ql, int qr){
    return query(1, 0, MAX - 1, ql, qr);
}

struct block{
    ll real;
    int mod;
    int begin;
    int end;
    int sz;

    block():real(0), mod(0), begin(0), end(0), sz(0){}
    block(ll real, int begin, int sz):real(real), begin(begin), end(begin + sz - 1), sz(sz){mod = real % moder; mod += mod < 0 ? moder : 0;}

    bool operator < (const block &b)const{
        return begin < b.begin;
    }
};

int a[N];
std::vector <pii> vec[N];
int ans[N];
std::deque <block> queue;
int power[N], invpower[N];

int main(){
    for (int i = 0; i < MAX << 1; ++ i){
        lazymult[i] = 1;
    }
    power[0] = invpower[0] = 1;
    for (int i = 1; i < N; ++ i){
        power[i] = power[i - 1] << 1;
        power[i] -= power[i] >= moder ? moder : 0;
        invpower[i] = 1ll * invpower[i - 1] * (moder + 1 >> 1) % moder;
    }
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = 0, l, r; i < q; ++ i){
        scanf("%d%d", &l, &r);
        -- l, -- r;
        vec[r].push_back({l, i});
    }
    for (int i = 0; i < n; ++ i){
        queue.push_back(block(a[i], i, 1));
        add(0, i, (a[i] % moder + moder) % moder);
        while (queue.size() >= 2 && queue.back().real >= 0){
            block lastblock = queue.back(); queue.pop_back();
            block preblock = queue.back(); queue.pop_back();
            mult(lastblock.begin, lastblock.end, power[preblock.sz]);
            add(0, preblock.end, 1ll * lastblock.mod * (power[preblock.sz] - 1 + moder) % moder);
            multmod(lastblock.mod, power[preblock.sz]);
            addmod(preblock.mod, lastblock.mod);
            if (lastblock.real > 0){
                if (preblock.sz > 100){
                    lastblock.real = INF;
                }
                else if (1.0 * pow(2, preblock.sz) * lastblock.real > INF){
                    lastblock.real = INF;
                }
                else{
                    lastblock.real *= 1ll << preblock.sz;
                }
            }
            preblock.sz += lastblock.sz;
            preblock.end = preblock.begin + preblock.sz - 1;
            preblock.real = std::min(INF, preblock.real + lastblock.real);
            queue.push_back(preblock);
        }
        for (auto u : vec[i]){
            if (u.first == i){
                ans[u.second] = (a[i] % moder + moder) % moder;
                continue;
            }
            int l = u.first + 1;
            int sit = std::upper_bound(queue.begin(), queue.end(), block(0, l, 0)) - queue.begin();
            if (sit != queue.size()){
                ans[u.second] = query(queue[sit].begin, queue[sit].begin);
            }
            int sum = query(l, l);
            submod(sum, ans[u.second]);
            multadd(ans[u.second], sum, invpower[l - queue[sit - 1].begin]);
            multmod(ans[u.second], 2);
            addmod(ans[u.second], (a[u.first] % moder + moder) % moder);
        }
    }
    for (int i = 0; i < q; ++ i){
        printf("%d\n", ans[i]);
    }
    return 0;
}