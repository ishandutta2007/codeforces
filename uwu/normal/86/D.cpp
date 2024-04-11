#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=200'001,MAXM=1e6+1,len=500;

ll arr[MAXN], cnt[MAXM], ans[MAXN], tot;
struct Query{ int l,r,id; };
bool cmp(Query &a, Query &b){
    return make_pair(a.l/len,a.r)<make_pair(b.l/len,b.r);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,q; cin >> n >> q;
    for (int i=1;i<=n;++i) cin >> arr[i];
    vector<Query> uwu;
    for (int i=1,l,r;i<=q;++i) cin >> l >> r, uwu.push_back({l,r,i});
    sort(uwu.begin(),uwu.end(),cmp);
    int pl=1,pr=0; ll a;
    for (Query x:uwu){
        while (pr<x.r){
            a=arr[pr+1];
            tot-=cnt[a]*cnt[a]*a;
            pr++; cnt[a]++;
            tot+=cnt[a]*cnt[a]*a;
        }
        while (pr>x.r){
            a=arr[pr];
            tot-=cnt[a]*cnt[a]*a;
            pr--; cnt[a]--;
            tot+=cnt[a]*cnt[a]*a;
        }
        while (pl>x.l){
            a=arr[pl-1];
            tot-=cnt[a]*cnt[a]*a;
            pl--; cnt[a]++;
            tot+=cnt[a]*cnt[a]*a;
        }
        while (pl<x.l){
            a=arr[pl];
            tot-=cnt[a]*cnt[a]*a;
            pl++; cnt[a]--;
            tot+=cnt[a]*cnt[a]*a;
        }
        ans[x.id]=tot;
    }
    for (int i=1;i<=q;++i) cout << ans[i] << '\n';
}