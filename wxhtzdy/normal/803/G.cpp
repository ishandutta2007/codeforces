#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 500;
const int M = 1e9 + 500;
const int INF = 0x3f3f3f3f;
const int LOG = 30;

int A[N], n, k, qq;
int mn[N][LOG], logara[N];

void tabeliraj(){
    logara[0] = logara[1] = 0;
    for(int i = 2;i < N;i++)logara[i] = logara[i / 2] + 1;
    for(int i = 1;i <= n;i++)mn[i][0] = A[i];
    for(int j = 1;j < LOG;j++){
        for(int i = 1;i + (1 << j) <= n + 1;i++){
            mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int brt(int l, int r){
    int lg = logara[r - l + 1];
    return min(mn[l][lg], mn[r - (1 << lg) + 1][lg]);
}

int egzel(int l, int r){
    int sajz = r - l + 1;
    if(sajz >= n)return brt(1, n);
    l = (l - 1) % n + 1;r = l + sajz - 1;
    if(r <= n)return brt(l, r);
    else return min(brt(l, n), brt(1, r - n));
}

int root, st[LOG * N], levo[LOG * N], desno[LOG * N], sld, lejzi[LOG * N];

void gurni(int node){
    if(!lejzi[node])return;
    if(!levo[node])levo[node] = ++sld;
    if(!desno[node])desno[node] = ++sld;
    lejzi[levo[node]] = lejzi[node];
    lejzi[desno[node]] = lejzi[node];
    st[levo[node]] = lejzi[node];
    st[desno[node]] = lejzi[node];
    lejzi[node] = 0; // gotova nodara
}

void postavi(int& node, int l, int r, int ll, int rr, int val){
    if(!node){
        node = ++sld;
        st[node] = egzel(l, r);
    }
    if(l > r || l > rr || r < ll)return;
    if(ll <= l && r <= rr){
        st[node] = val;
        lejzi[node] = val;
        return;
    }
    gurni(node);
    int mid = (l + r) / 2;
    postavi(levo[node], l, mid, ll, rr, val);
    postavi(desno[node], mid + 1, r, ll, rr, val);
    st[node] = min(st[levo[node]], st[desno[node]]);
}

int bracala(int node, int l, int r, int ll, int rr){
    if(l > r || l > rr || r < ll)return INF;
    if(ll <= l && r <= rr){
        if(!node)return egzel(l, r);
        return st[node];
    }
    gurni(node);
    int mid = (l + r) / 2;
    return min(bracala(levo[node], l, mid, ll, rr), bracala(desno[node], mid + 1, r, ll, rr));
}

int main(){
    scanf("%d%d", &n, &k);
    for(int i = 1;i <= n;i++){
        scanf("%d", A + i);
    }
    tabeliraj();
    scanf("%d", &qq);
    while(qq--){
        int type; scanf("%d", &type);
        if(type == 1){
            int l, r, x; scanf("%d%d%d", &l, &r, &x);
            postavi(root, 1, M, l, r, x);
        }else{
            int l, r; scanf("%d%d", &l, &r);
            printf("%d\n", bracala(root, 1, M, l, r));
        }
    }
    return 0;
}