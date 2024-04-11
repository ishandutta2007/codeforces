#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1000005;
int stk[maxn], a[maxn], ls[maxn], rs[maxn], tp=0, cnt=0;
void insert(int x) {
    int k=tp;a[++cnt]=x;
    while (k>0&&a[stk[k]]<a[cnt]) k--;
    if(k) rs[stk[k]]=cnt;
    if(k<tp) ls[cnt]=stk[k+1];
    stk[++k]=cnt;
    tp=k;
}
int ans[maxn];
void dfs(int u, int dep) {
    ans[u] = dep;
    if(ls[u]) dfs(ls[u], dep+1);
    if(rs[u]) dfs(rs[u], dep+1);
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;++i) a[i]=ls[i]=rs[i]=0;
        tp=cnt=0;
        for(int i=0;i<n;++i) {
            int x;
            cin>>x;
            insert(x);
        }
        dfs(stk[1], 0);
        for(int i=1;i<=n;++i) cout<<ans[i]<<" ";cout<<endl;
    }
}