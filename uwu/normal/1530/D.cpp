#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> a(n+1), b(n+1), from(n+1), seen(n+1), sa, sb;
        for (int i=1;i<=n;++i){
            cin >> a[i];
            if (!seen[a[i]]) b[i]=a[i], from[a[i]]=i, seen[a[i]]=1;
            else sa.push_back(i); 
        }
        for (int i=1;i<=n;++i){
            if (!seen[i]) sb.push_back(i);
        }
        if (sa.size()==1&&sa[0]==sb[0]){
            int v=sa[0];
            int u=from[a[v]];
            b[u]=v, b[v]=a[v];
        }
        else if (!sa.empty()){
            fill(seen.begin(),seen.end(),0);
            for (int x:sa) seen[x]++;
            for (int x:sb) seen[x]++;
            for (int i=1;i<=n;++i) if (seen[i]==1) seen[i]=0;
            sort(sa.begin(),sa.end(),[&](int a, int b){ return a+(seen[a]?inf:0)<b+(seen[b]?inf:0); });
            sort(sb.begin(),sb.end(),[&](int a, int b){ return a+(seen[a]?inf:0)<b+(seen[b]?inf:0); });
            for (int i=1;i<sa.size();++i) b[sa[i]]=sb[i-1];
            b[sa[0]]=sb.back();
        }
        int ans=0;
        for (int i=1;i<=n;++i) if (a[i]==b[i]) ans++;
        cout << ans << '\n';
        for (int i=1;i<=n;++i) cout << b[i] << " ";
        cout << '\n';
    }
}