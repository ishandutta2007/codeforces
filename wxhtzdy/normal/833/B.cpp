#include<bits/stdc++.h>
using namespace std;
const int MAXN = 35010;
int dp[MAXN+10], Max[MAXN*4+10], flg[MAXN*4+10];
void push_down(int u){
    if(flg[u]){
        Max[u<<1] += flg[u];
        Max[u<<1|1] += flg[u];
        flg[u<<1] += flg[u];
        flg[u<<1|1] += flg[u];
        flg[u] = 0;
    }
}
void Insert(int u, int l, int r, int pos, int val){
    if(l == r){
        Max[u]=val, flg[u]=0;
        return ;
    }
    int mid=(l+r)>>1;
    push_down(u);
    if(pos<=mid) Insert(u<<1,l,mid,pos,val);
    else Insert(u<<1|1,mid+1,r,pos,val);
    Max[u]=max(Max[u<<1],Max[u<<1|1]);
}
void Insert_add(int u, int l, int r, int L, int R, int val){
    if(L<=l&&r<=R){
        Max[u]+=val;
        flg[u]+=val;
        return ;
    }
    int mid=(l+r)>>1;
    push_down(u);
    if(L<=mid) Insert_add(u<<1,l,mid,L,R,val);
    if(R>mid) Insert_add(u<<1|1,mid+1,r,L,R,val);
    Max[u]=max(Max[u<<1],Max[u<<1|1]);
}
int Query(int u, int l, int r, int L, int R){
    if(L <= l && r <= R) return Max[u];
    int mid=(l+r)>>1, ret=0;
    push_down(u);
    if(L<=mid) ret=max(ret,Query(u<<1,l,mid,L,R));
    if(R>mid) ret=max(ret,Query(u<<1|1,mid+1,r,L,R));
    return ret;
}
int a[MAXN+10], q[MAXN+10], qcnt, pre_pos[MAXN+10], tmp_pos[MAXN+10];
int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
        q[i] = a[i];
    }
    sort(q+1, q+1+n);
    qcnt=unique(q+1, q+1+n)-q-1;
    for(int i=1;i<=n;i++){
        a[i] = lower_bound(q+1, q+1+qcnt, a[i])-q;
        pre_pos[i] = tmp_pos[a[i]];
        tmp_pos[a[i]] = i;
    }
    while(k--){
        Insert(1, 0, n, 0, 0);
        for(int i=1;i<=n;i++){
            Insert_add(1, 0, n, pre_pos[i], i-1, 1);
            Insert(1, 0, n, i, dp[i]);
            dp[i] = max(dp[i], Query(1, 0, n, 0, i));
        }
    }
    printf("%d\n", dp[n]);

    return 0;
}