#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define f first
#define s second
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+10;

int ans[MAXN];
vector<int> pos[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n,x,y; cin >> n >> x >> y; y-=x;
        for (int i=1;i<=n+1;++i) pos[i].clear(), ans[i]=0;
        for (int i=1,a;i<=n;++i){
            cin >> a; pos[a].push_back(i);
        }
        int unseen;
        priority_queue<pii> pq;
        for (int i=1;i<=n+1;++i){
            if (pos[i].size()==0) unseen=i;
            else pq.push({pos[i].size(),i});
        }
        for (int i=1;i<=x;++i){
            pii temp=pq.top(); pq.pop();
            ans[pos[temp.s].back()]=temp.s;
            pos[temp.s].pop_back();
            if (temp.f-1!=0) pq.push({temp.f-1,temp.s});
        }
        vector<pii> uwu;
        int most=0;
        for (int i=1;i<=n+1;++i){
            if (pos[i].size()==0) continue;
            most=max(most,(int)pos[i].size());
            for (int j=0;j<pos[i].size();++j) uwu.push_back({pos[i][j],i});
        }
        //for (pii x:uwu) cout << x.f << ":" << x.s << " | ";
        int cnt=0;
        for (int i=0;i<uwu.size();++i){
            most%=uwu.size();
            if (cnt==y) break;
            if (uwu[i].s!=uwu[most].s) cnt++, ans[uwu[i].f]=uwu[most++].s;
        }
        if (cnt!=y){ cout << "NO" << '\n'; continue; }
        cout << "YES" << '\n';
        for (int i=1;i<=n;++i){
            if (ans[i]==0) cout << unseen << " ";
            else cout << ans[i] << " ";
        }
        cout << '\n';
    }
}