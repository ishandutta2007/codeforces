#include<bits/stdc++.h>

const int N = 200010;
const int MAX = 1 << 18;

struct Matrix{
    static const int BIT = 30;

    int a[BIT];

    Matrix():a(){}

    explicit Matrix(int value):a(){
        if (!value) {
            return;
        }
        for (int i = BIT - 1; i >= 0; -- i){
            if (value >> i & 1){
                a[i] = value;
                return;
            }
        }
    }

    void merge(const Matrix &m){
        Matrix tmp = m;
        for (int i = 0; i < BIT; ++ i){
            if (!tmp.a[i]){
                continue;
            }
            for (int j = i; tmp.a[i] && j >= 0; -- j){
                if (tmp.a[i] >> j & 1){
                    if (a[j]){
                        tmp.a[i] ^= a[j];
                    }
                    else{
                        a[j] = tmp.a[i];
                        break;
                    }
                }
            }
        }
    }
};

Matrix seg[MAX << 1];
int seg1[MAX << 1], a[N];

void add(int sit, int value){
    seg[sit += MAX] = Matrix(value);
    for (sit >>= 1; sit; sit >>= 1){
        seg[sit] = seg[sit << 1];
        seg[sit].merge(seg[sit << 1 | 1]);
    }
}

Matrix query(int l, int r){
    Matrix ret;
    for (l += MAX, r += MAX + 1; l < r; l >>= 1, r >>= 1){
        if (l & 1) ret.merge(seg[l ++]);
        if (r & 1) ret.merge(seg[-- r]);
    }
    return ret;
}

void add1(int sit, int value){
    seg1[sit += MAX] ^= value;
    for (sit >>= 1; sit; sit >>= 1){
        seg1[sit] = seg1[sit << 1] ^ seg1[sit << 1 | 1];
    }
}

int query1(int l, int r){
    int ret = 0;
    for (l += MAX, r += MAX + 1; l < r; l >>= 1, r >>= 1){
        if (l & 1) ret ^= seg1[l ++];
        if (r & 1) ret ^= seg1[-- r];
    }
    return ret;
}

int query2(int sit){
    return a[0] ^ query1(1, sit);
}

int main(){
    int n, test;
    scanf("%d%d", &n, &test);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; ++ i){
        int value = a[i] ^ a[i - 1];
        seg[i + MAX] = Matrix(value);
        seg1[i + MAX] = value;
    }
    for (int i = MAX - 1; i; -- i){
        seg[i] = seg[i << 1];
        seg[i].merge(seg[i << 1 | 1]);
        seg1[i] = seg1[i << 1] ^ seg1[i << 1 | 1];
    }
    while (test --){
        int type;
        scanf("%d", &type);
        int l, r;
        scanf("%d%d", &l, &r);
        -- l, -- r;
        if (type == 1){
            int k;
            scanf("%d", &k);
            if (l > 0){
                add(l, query1(l, l) ^ k);
            }
            if (r < n - 1){
                add(r + 1, query1(r + 1, r + 1) ^ k);
            }
            if (l == 0){
                a[0] ^= k;
            }
            else{
                add1(l, k);
            }
            if (r < n - 1){
                add1(r + 1, k);
            }
        }
        else{
            Matrix mat = query(l + 1, r);
            mat.merge(Matrix(query2(l)));
            int cnt = 0;
            for (int i = 0; i < Matrix::BIT; ++ i){
                cnt += mat.a[i] != 0;
            }
            printf("%d\n", 1 << cnt);
        }
    }
    return 0;
}