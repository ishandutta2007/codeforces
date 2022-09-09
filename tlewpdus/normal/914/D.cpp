#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,ll> pll;

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b,a%b);
}

int n;
int arr[500100];

struct idxtree {
    int tree[1050000];
    int key = 524288;
    void init() {
        int i;
        for (i=0;i<n;i++) tree[key+i] = arr[i];
        for (i=key-1;i>0;i--) tree[i] = gcd(tree[i*2],tree[i*2+1]);
    }
    void upd(int idx, int val) {
        idx += key;
        tree[idx] = val; idx /= 2;
        while(idx>0) {
            tree[idx] = gcd(tree[idx*2],tree[idx*2+1]);
            idx /= 2;
        }
    }
    int getv(int l, int r) {
        l += key; r += key;
        int g = 0;
        while(l<=r) {
            if (l&1) g = gcd(g,tree[l]);
            if (~r&1) g = gcd(g,tree[r]);
            l = (l+1)/2, r = (r-1)/2;
        }
        return g;
    }
    int getr(int l, int r, int x) {
        vector<int> typ, tmp;
        int tl = l, tr = r;
        l += key; r += key;
        while(l<=r) {
            if (l&1) typ.push_back(l);
            if (~r&1) tmp.push_back(r);
            l = (l+1)/2; r = (r-1)/2;
        }
        while(!tmp.empty()) {
            typ.push_back(tmp.back());
            tmp.pop_back();
        }
        int i = 0;
        for (i=0;i<typ.size();i++) {
            if (tree[typ[i]]%x!=0) break;
        }
        if (i==typ.size()) return tr+1;
        int v = typ[i];
        while(v<key) {
            if (tree[v*2]%x==0) v = v*2+1;
            else v = v*2;
        }
        return v-key;
    }
} it;

int main() {
    int i;
    scanf("%d",&n);
    for (i=0;i<n;i++) scanf("%d",&arr[i]);
    it.init();
    int q;
    scanf("%d",&q);
    for (i=0;i<q;i++) {
        int a;
        scanf("%d",&a);
        if (a==1) {
            int b, c, d;
            scanf("%d%d%d",&b,&c,&d);
            b--;c--;
            int v = it.getr(b,c,d);
            if (v>=c) printf("YES\n");
            else {
                if (it.getv(v+1,c)%d==0) puts("YES");
                else puts("NO");
            }
        }
        else {
            int b, c;
            scanf("%d%d",&b,&c);
            b--;
            it.upd(b,c);
        }
    }

    return 0;
}