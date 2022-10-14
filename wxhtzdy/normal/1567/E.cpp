#include <bits/stdc++.h>
#define ff(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
#define fb(i,a,b) for(int (i) = (a); (i) >= (b); --(i))
#define LL long long
using namespace std;

struct cvor{
    LL val;
    int lzy;
    bool act;
}st[800005];

int n, q;
int a[200005];
int ind[200005];

void propagate(int node, int l, int r){
    if(st[node].act){
        st[node].val = st[node].lzy * (LL) (r - l + 1);
        st[node].act = false;
        if(l != r){
            st[node * 2].act = true;
            st[node * 2].lzy = st[node].lzy;
            st[node * 2 + 1].act = true;
            st[node * 2 + 1].lzy = st[node].lzy;
        }
    }
}

void build(int node, int l, int r){
    if(l == r){ st[node].val = ind[l]; return;}
    int mid = l + r >> 1;
    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);
    st[node].val = st[node * 2].val + st[node * 2 + 1].val;
}

LL get(int node, int l, int r, int ll, int rr){
    propagate(node, l, r);
    if(l > r || l > rr || r < ll)return (LL)0;
    if(ll <= l && r <= rr)return st[node].val;
    int mid = l + r >> 1;
    return get(node * 2, l, mid, ll, rr) + get(node * 2 + 1, mid + 1, r, ll, rr);
}

void update(int node, int l, int r, int ll, int rr, int val){
    propagate(node, l, r);
    if(l > r || l > rr || r < ll)return;
    if(ll <= l && r <= rr){
        st[node].lzy = val;
        st[node].act = true;
        propagate(node, l, r);
        return;
    }
    int mid = l + r >> 1;
    update(node * 2, l, mid, ll, rr, val);
    update(node * 2 + 1, mid + 1, r, ll, rr, val);
    st[node].val = st[node * 2].val + st[node * 2 + 1].val;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> q;
    ff(i,0,n-1)cin >> a[i];
    ff(i,0,n-1){
        if(i == 0 || a[i] < a[i - 1])ind[i] = i;
        else ind[i] = ind[i - 1];
    }
    build(1, 0, n - 1);
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int x, y;
            cin >> x >> y;
            --x;
            a[x] = y;
            if(x == 0 || a[x] < a[x - 1])update(1, 0, n - 1, x, x, x);
            else update(1, 0, n - 1, x, x, get(1, 0, n - 1, x - 1, x - 1));
            int bot = x + 1, top = n - 1, ans = x;
            while(bot <= top){
                int mid = bot + top >> 1;
                if(get(1, 0, n - 1, mid, mid) <= x + 1){
                    ans = mid;
                    bot = mid + 1;
                }else{
                    top = mid - 1;
                }
            }
            if(x + 1 < n && a[x] > a[x + 1])update(1, 0, n - 1, x + 1, ans, x + 1);
            if(x + 1 < n && a[x] <= a[x + 1])update(1, 0, n - 1, x + 1, ans, get(1, 0, n - 1, x, x));
        }
        else{
            int l, r;
            cin >> l >> r;
            --l; --r;
            int bot = l, top = r, ans = l;
            while(bot <= top){
                int mid = bot + top >> 1;
                if(get(1, 0, n - 1, mid, mid) <= l){
                    ans = mid;
                    bot = mid + 1;
                }else{
                    top = mid - 1;
                }
            }
            LL res = (ans + 1) * (LL) (ans + 2) / 2 - l * (LL) (l + 1) / 2 - l * (LL) (ans - l + 1);
            if(ans < r){
                res += (r + 1) * (LL) (r + 2) / 2 - (ans + 1) * (LL) (ans + 2) / 2 - get(1, 0, n - 1, ans + 1, r);
            }
            cout << res << "\n";
        }
    }
}