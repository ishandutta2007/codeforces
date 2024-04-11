#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<iostream>

using namespace std;
typedef long long int lint;

struct node{
    lint val;
    node * l, * r;
    node(){}
    node(lint v){val = v; l = NULL; r = NULL;}
};

int n, k;
vector<vector<lint> > dp;
vector<lint> sum;
vector<lint> cs;
vector<int> a;
node * root;

node * build(int l, int r){
    if(l == r){
        return new node(cs[l]);
    }
    int m = (l + r) >> 1;
    node * nnode = new node;
    nnode->l = build(l, m);
    nnode->r = build(m + 1, r);
    nnode->val = nnode->l->val + nnode->r->val;
    return nnode;
}

void recreate(node * v, int l, int r){
    if(l == r){v->val = cs[l];}
    else{
        int m = (l + r) >> 1;
        recreate(v->l, l, m);
        recreate(v->r, m + 1, r);
        v->val = v->l->val + v->r->val;
    }
}

void upd(node * v, int l, int r, int pos, lint nv){
    if(l == r){
        cs[l] = nv;
        v->val = nv;
        return;
    }
    int m = (l + r) >> 1;
    if(pos <= m){upd(v->l, l, m, pos, nv);}
    else{upd(v->r, m + 1, r, pos, nv);}
    v->val = v->l->val + v->r->val;
}

lint get(node * v, int l, int r, int ul, int ur){
    if(ul > ur){return 0;}
    if(ul == l && ur == r){return v->val;}
    int m = (l + r)/2;
    return get(v->l, l, m, ul, min(ur, m)) + get(v->r, m + 1, r, max(ul, m + 1), ur);
}

int main(){
    scanf("%d%d", &n, &k);
    if(k + 1 > n){printf("0"); return 0;}
    dp.resize(n); cs.resize(n + 1); sum.resize(n + 1); a.resize(n);
    for(int i = 0; i < n; i++){
        dp[i].resize(k + 2);
        scanf("%d", &a[i]);
    }
    cs.assign(n + 1, 0); root = build(0, n);
    for(int j = 1; j <= k + 1; j++){
        if(j == 1){sum.assign(n + 1, 0);}
        cs.assign(n + 1, 0);
        recreate(root, 0, n);
        for(int i = 0; i < n; i++){
            if(j == 1){dp[i][j] = 1; sum[a[i]] = get(root, 0, n, 1, a[i] - 1); upd(root, 0, n, a[i], dp[i][j]); continue;}
            dp[i][j] = sum[a[i]];
            upd(root, 0, n, a[i], dp[i][j]);
            sum[a[i]] = get(root, 0, n, 1, a[i] - 1);
        }
    }
    lint ans = 0;
    for(int i = 0; i < n; i++){
        ans += dp[i][k + 1];
    }
    printf("%lld", ans);
    return 0;
}