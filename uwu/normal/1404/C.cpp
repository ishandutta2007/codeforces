#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7,seed=131,MAXN=3e5+1;

int arr[MAXN], bit[MAXN], ans[MAXN], p;
struct Query{ int l,r,id; } qs[MAXN];

bool cmp(Query a, Query b){
    return a.r<b.r; 
}

int get(int idx){
    int ans=0;
    for (int i=idx;i>0;i-=(i)&(-i)) ans+=bit[i];
    return ans;
}

void ins(int val){
    int l=0, r=p, mid=1;
    while (l<r){
        mid=(l+r+1)>>1;
        if (get(mid)>=val) l=mid;
        else r=mid-1;
    }
    if (val<0) return;
    for (int i=l+1;i<MAXN;i+=(i)&(-i)) bit[i]--;
    for (int i=1;i<MAXN;i+=(i)&(-i)) bit[i]++;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for (int i=1;i<=n;++i) cin >> arr[i], arr[i]=i-arr[i];
    for (int i=1,a,b;i<=q;++i){
        cin >> a >> b;
        qs[i]={a+1,n-b,i};
    }
    sort(qs+1,qs+1+q,cmp);
    for (int idx=1;idx<=q;++idx){
        Query x=qs[idx];
        while (p<x.r){
            ins(arr[++p]);
        }
        ans[x.id]=get(x.l);
    }
    for (int i=1;i<=q;++i) cout << ans[i] << '\n';
}