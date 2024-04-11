#include <bits/stdc++.h>

using namespace std;

const int N = 250010;

struct segtree {
    struct info{
        int fill;
        info(int fill = 0) {
            this->fill = fill;
        }
        int get() {
            return fill;
        }
        info change(int L, int R) {
            return info(R - L + 1 - fill);
        }
        static info merge(const info& a, const info& b) {
            return info(a.fill + b.fill);
        }
        static info empty() {
            return info(0);
        }
    };
    struct node{
        info value;
        int laz;
        node *sonL, *sonR;
        node(info value = info(), int laz = 0, 
            node *sonL = NULL, node *sonR = NULL) {
            this->value = value;
            this->sonL = sonL;
            this->sonR = sonR;
            this->laz = laz;
        }
        node(const node& oth) {
            this->value = oth.value;
            this->laz = oth.laz;
            this->sonL = oth.sonL;
            this->sonR = oth.sonR;
        }
    };

    static node* build(int L, int R) {
        if (L == R) return new node();
        node *sonL = build(L, (L + R) / 2);
        node *sonR = build((L + R) / 2 + 1, R);
        return new node(info(), 0, sonL, sonR);
    }
    static node* build() {
        return build(1, N);
    }
    static node* propagate(node *cur, int L, int R) {
        if (!cur->laz) {
            return cur;
        }
        if (L == R) {
            return cur;
        }
        int mid = (L + R) / 2;
        node* sonL = new node(*cur->sonL); 
        node* sonR = new node(*cur->sonR);

        sonL->value = sonL->value.change(L, mid);
        sonR->value = sonR->value.change(mid + 1, R);
        sonL->laz ^= 1;
        sonR->laz ^= 1;
        return new node(cur->value, 0, sonL, sonR);
    }
    
    /*
    static node* update(node *cur, int L, int R, int l, int r) {
        cur = propagate(cur, L, R);

        if (L > r || R < l) return cur;
        if (l <= L && R <= r) {
            return new node(cur->value.change(L, R), 1, cur->sonL, cur->sonR);
        }
        int mid = (L + R) / 2;
        node* sonL = update(cur->sonL, L, mid, l, r);
        node* sonR = update(cur->sonR, mid + 1, R, l, r);
        return new node(info::merge(sonL->value, sonR->value), 0, sonL, sonR);
    }
    static node* update(node *cur, int l, int r) {
        return update(cur, 1, N, l, r);
    }

    static info get(node *cur, int L, int R, int l, int r) {
        if (l > R || R < l) return info::empty();
        if (l <= L && R <= r) {
            return cur->value; 
        }

        cur = propagate(cur, L, R);

        int mid = (L + R) / 2;
        info leftInfo = get(cur->sonL, L, mid, l, r);
        info rightInfo = get(cur->sonR, mid + 1, R, l, r);
        return info::merge(leftInfo, rightInfo);
    }
    static info get(node *cur, int l, int r) {
        return get(cur, 1, N, l, r);
    }*/
    static pair<node*, bool> rangeFlip(node *cur, int L, int R, int pos) {
        if (L == R) {
            int sign = cur->value.fill;    
            return make_pair(new node(info(sign ^ 1), 0, NULL, NULL), sign);
        }
        cur = propagate(cur, L, R);
        if (pos == R && cur->value.fill == R - L + 1) {
            return make_pair(new node(info(0), 1, cur->sonL, cur->sonR), true); 
        }
        int mid = (L + R) / 2;
        if (pos <= mid) {
            pair<node*, bool> left = rangeFlip(cur->sonL, L, mid, pos);
            return make_pair(new node(info::merge(left.first->value, cur->sonR->value), 0, left.first, cur->sonR), left.second);
        }

        pair<node*, bool> right = rangeFlip(cur->sonR, mid + 1, R, pos);
        pair<node*, bool> left = right.second ? 
            rangeFlip(cur->sonL, L, mid, mid) :
            make_pair(cur->sonL, false);
        
        return make_pair(new node(info::merge(left.first->value, right.first->value), 0, left.first, right.first), left.second);
    }
    static pair<node*, bool> rangeFlip(node *cur, int pos) {
        return rangeFlip(cur, 1, N, pos);
    }
};

segtree::node* root[N];

int ans[N];
int a[N][2];
bool attack(int x, int dam) {
    dam = a[x][1] - dam;
    if (dam <= 0) return 1;
    pair<segtree::node*, bool> result = segtree::rangeFlip(root[x], dam);
    root[x] = result.first;
    return result.second;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;


    int rn = 0;
    root[0] = segtree::build();
    memset(ans, -1, sizeof(ans));
    for(int i = 1; i <= n; i++){
        int type;
        cin >> type;
        if (type == 1) {
            root[++rn] = root[0];
            a[rn][0] = a[rn][1] = 1;
            continue;
        }
        if (type == 5) {
            int x, y;
            cin >> x >> y;
            if (ans[x] != -1 || ans[y] != -1) continue;
            if (attack(x, a[y][0])) ans[x] = i;
            if (attack(y, a[x][0])) ans[y] = i;
            continue;
        }
        int x;
        cin >> x;
        if (type == 2) a[x][0]++;
        if (type == 3) a[x][1]++;
        if (type == 4) {
            root[++rn] = root[x];
            a[rn][0] = a[x][0];
            a[rn][1] = a[x][1];
            if (ans[x] != -1) ans[rn] = i;
        }
    }
    cout << rn << '\n';
    for(int i = 1; i <= rn; i++) cout << ans[i] << " ";
}